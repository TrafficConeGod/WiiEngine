#include "BouncingBallGenerator.h"
#include "stageLinks.h"

void BouncingBallGenerator::ButtonPressed() {
    DataStream stream(MainStage.buf, MainStage.size);
    CreateChildFrom(stream);
}