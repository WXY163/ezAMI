#include "compiler.h"
#include <QFileDialog>


compiler::compiler(QWidget *parent) : QDialog(parent),ui(new Ui::Compiler_Dialog)
{
    ui->setupUi(this);
    process = new QProcess();
}
compiler::~compiler()
{
    delete process;
}

QString compiler::getSourcePath()
{
    return directory;
}

void compiler::compile()
{

}

void compiler::generateDll()
{

}

void compiler::on_gccPathToolButton_clicked()
{
   cppComplier = QFileDialog::getOpenFileName(this, tr("Select compiler"), "C:",
            tr(".exe (*.exe)"));
    ui->gccPathLineEdit->setText(cppComplier);
}



void compiler::on_generalGccCheckBox_clicked(bool checked)
{
    if(checked == true)
        cppComplier = "gcc";
    else {
        cppComplier = ui->gccPathLineEdit->text();
    }
}

void compiler::on_buildPushButton_clicked()
{
    QString program = "gcc";
    QStringList argu, argu1;
    argu<<"-c"<<"-o"<<"/Research/ezAMI/AMI/ami.o"<<"F:/Research/ezAMI/AMI/ami.cpp"<<"-D"<<"ADD_EXPORTS";
    argu1<<"-o"<<"F:/Research/ezAMI/ezAMI/debug/ami.dll"<<"-s"<<"-shared"<<"F:/Research/ezAMI/AMI/ami.o"<<"-Wl,--subsystem,windows";
    //QProcess::execute("gcc -c -o F:/Research/C++/exampe.o F:/Research/C++/example.cpp -D ADD_EXPORTS");
    process->start(program,argu);
    if(process->waitForFinished()){
        if(process->exitCode() == 0){
            ui->textBrowser->append(process->readAllStandardOutput());
            process->start(program,argu1);
            if(process->waitForFinished()){
                if(process->exitCode()==0)
                {
                    ui->textBrowser->append(process->readAllStandardOutput());
                    ui->textBrowser->append("Compile finished without error!");
                }
                else
                {
                    ui->textBrowser->append(process->readAllStandardError());

                }
            }
        }

        else
            ui->textBrowser->append(process->readAllStandardError());
    }

}
