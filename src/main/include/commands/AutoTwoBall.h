#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

class AutoTwoBall
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTwoBall> {
 public:
  AutoTwoBall();
};
