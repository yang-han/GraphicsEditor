#include "Commands/reset_command.h"
#include "ViewModel/viewmodel.h"
#include "command.h"
#include <QDebug>
#include <string>


void ResetCommand::exec() {
	viewmodel->exec_reset_command();
}

