#include "filter_command.h"
#include "viewmodel.h"
#include "command.h"
#include <QDebug>
#include <string>

void FilterRemCommand::exec(){
    viewmodel->exec_filter_rem_command();
}
