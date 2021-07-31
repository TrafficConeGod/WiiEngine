#include "debug.h"
#include "wii/io.h"
#include "wii/textures_tpl.h"
#include "wii/textures.h"
#include "World.h"
#include "actors/Sprite.h"
#include "actors/Inputtable.h"
#include "actors/BouncingBall.h"
#include "actors/Character.h"
#include "templates.h"

#define DEFAULT_FIFO_SIZE (256*1024)

static void* frameBuffer[2] = { NULL, NULL};
static GXRModeObj* rMode;

GXTexObj texObj;

void CreateAction(Actor* actor) {
	actor->Create();
}

void UpdateAction(Actor* actor) {
	actor->Update();
}

void DrawAction(Actor* actor) {
	auto sprite = dynamic_cast<Sprite*>(actor);
	sprite->Draw();
}

void ButtonPressedAction(Actor* actor) {
	auto inputtable = dynamic_cast<Inputtable*>(actor);
	inputtable->ButtonPressed();
}

int main(int argc, char** argv){
	#ifndef PC_DEBUG

	u32	frameBuf; 	// initial framebuffer index
	u32 firstFrame;
	f32 yScale;
	u32 xfbHeight;
	Mtx44 perspective;
	Mtx GXmodelView2D;
	void* gpFifo = NULL;

	GXColor background = {0, 0, 0, 0xff};

	VIDEO_Init();

	rMode = VIDEO_GetPreferredMode(NULL);

	frameBuf = 0;
	firstFrame = 1;
	// allocate 2 framebuffers for double buffering
	frameBuffer[0] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rMode));
	frameBuffer[1] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rMode));

	VIDEO_Configure(rMode);
	VIDEO_SetNextFramebuffer(frameBuffer[frameBuf]);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if (rMode->viTVMode & VI_NON_INTERLACE) {
		VIDEO_WaitVSync();
	}

	frameBuf ^= 1;

	// setup the fifo and then init the flipper
	gpFifo = memalign(32, DEFAULT_FIFO_SIZE);
	memset(gpFifo, 0, DEFAULT_FIFO_SIZE);

	GX_Init(gpFifo, DEFAULT_FIFO_SIZE);

	// clears the bg to color and clears the z buffer
	GX_SetCopyClear(background, 0x00ffffff);

	// other gx setup
	GX_SetViewport(0, 0, rMode->fbWidth, rMode->efbHeight, 0, 1);
	yScale = GX_GetYScaleFactor(rMode->efbHeight, rMode->xfbHeight);
	xfbHeight = GX_SetDispCopyYScale(yScale);
	GX_SetScissor(0, 0, rMode->fbWidth, rMode->efbHeight);
	GX_SetDispCopySrc(0, 0, rMode->fbWidth, rMode->efbHeight);
	GX_SetDispCopyDst(rMode->fbWidth, xfbHeight);
	GX_SetCopyFilter(rMode->aa, rMode->sample_pattern, GX_TRUE, rMode->vfilter);
	GX_SetFieldMode(rMode->field_rendering, ((rMode->viHeight == 2 * rMode->xfbHeight) ? GX_ENABLE : GX_DISABLE));

	if (rMode->aa) {
		GX_SetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
	} else {
		GX_SetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
	}


	GX_SetCullMode(GX_CULL_NONE);
	GX_CopyDisp(frameBuffer[frameBuf], GX_TRUE);
	GX_SetDispCopyGamma(GX_GM_1_0);

	// setup the vertex descriptor
	// tells the flipper to expect direct data
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_F32, 0);
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);


	GX_SetNumChans(1);
	GX_SetNumTexGens(1);
	GX_SetTevOp(GX_TEVSTAGE0, GX_REPLACE);
	GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
	GX_SetTexCoordGen(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY);


	GX_InvalidateTexAll();

	TPLFile spriteTPL;
	TPL_OpenTPLFromMemory(&spriteTPL, (void*)textures_tpl, textures_tpl_size);
	TPL_GetTexture(&spriteTPL, ballsprites, &texObj);
	GX_LoadTexObj(&texObj, GX_TEXMAP0);

	guOrtho(perspective, 0, 479, 0, 639, 0, 300);
	GX_LoadProjectionMtx(perspective, GX_ORTHOGRAPHIC);

	WPAD_Init();

	srand(time(NULL));

	#endif

	World world;
	for (size_t i = 0; i < 1; i++) {
		world.AllocateActor(BouncingBall::ID);
	}
	world.AllocateActor(Character::ID);
	world.DoAction(CreateAction);

	while (true) {

		#ifndef PC_DEBUG

		WPAD_ScanPads();

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {
			exit(0);
		}

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_A) {
			world.DoActionOn(Inputtable::ID, ButtonPressedAction);
		}

		GX_SetViewport(0, 0, rMode->fbWidth, rMode->efbHeight, 0, 1);
		GX_InvVtxCache();
		GX_InvalidateTexAll();

		GX_ClearVtxDesc();
		GX_SetVtxDesc(GX_VA_POS, GX_DIRECT);
		GX_SetVtxDesc(GX_VA_TEX0, GX_DIRECT);

		guMtxIdentity(GXmodelView2D);
		guMtxTransApply(GXmodelView2D, GXmodelView2D, 0.0F, 0.0F, -5.0F);
		GX_LoadPosMtxImm(GXmodelView2D, GX_PNMTX0);

		#endif

		world.DoAction(UpdateAction);
		world.DoActionOn(Sprite::ID, DrawAction);

		#ifndef PC_DEBUG

		GX_DrawDone();

		GX_SetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		GX_SetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GX_SetAlphaUpdate(GX_TRUE);
		GX_SetColorUpdate(GX_TRUE);
		GX_CopyDisp(frameBuffer[frameBuf], GX_TRUE);

		VIDEO_SetNextFramebuffer(frameBuffer[frameBuf]);
		if (firstFrame) {
			VIDEO_SetBlack(FALSE);
			firstFrame = 0;
		}
		VIDEO_Flush();
		VIDEO_WaitVSync();
		frameBuf ^= 1;		// flip framebuffer

		#endif
	}
	return 0;
}