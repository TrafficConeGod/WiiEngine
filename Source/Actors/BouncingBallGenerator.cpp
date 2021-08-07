#include "BouncingBallGenerator.h"
#include "stageLinks.h"

void BouncingBallGenerator::ButtonPressed(uint buttonType) {
    if (buttonType & WPAD_BUTTON_A) {
        DataStream stream(MainStage.buf, MainStage.size);
        CreateChildFrom(stream);
    } else if (buttonType & WPAD_BUTTON_B) {
        Destroy();
    }
}