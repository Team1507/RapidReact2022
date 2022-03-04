#include "commands/CmdLimeLight3xMode.h"


CmdLimeLight3xMode::CmdLimeLight3xMode(Shooter *shooter, bool is3xMode) 
{
    m_shooter = shooter;
    m_is3xOn = is3xMode;
}


void CmdLimeLight3xMode::Initialize() 
{
    //m_shooter->LimeLight3xMode(m_is3xOn);
}
