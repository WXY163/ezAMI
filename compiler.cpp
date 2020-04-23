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
    QString program = "gcc";
    QStringList argu, argu1;
    argu<<"-c"<<"-o"<<"/Research/ezAMI/AMI/ami.o"<<"F:/Research/ezAMI/AMI/ami.cpp"<<"-D"<<"ADD_EXPORTS";
    argu1<<"-o"<<"F:/Research/ezAMI/AMI/ami.dll"<<"-s"<<"-shared"<<"F:/Research/ezAMI/AMI/ami.o"
        <<"-Wl,--subsystem,windows";
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
                    ui->textBrowser->append("Build finish!");
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

void compiler::generateDll()
{
    QString cl = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.25.28610/bin/HostX86/x64/cl.exe";
    QString link = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.25.28610/bin/HostX86/x64/LINK.exe";

    QString INC_VS = tr("C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.25.28610/include");
    QString INC_SDK_SH = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/shared";
    QString INC_SDK_UM = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/um";
    QString INC_SDK_UCRT = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/ucrt";
    QString INC_USR = "F:/Research/ibis-AMI/learning/cmd";
    QStringList argu;
    QStringList arguTest("");
    argu<<"/c"<<"/I"<<INC_USR<<"/I"<<INC_VS<<"/I"<<INC_SDK_SH<<"/I"<<INC_SDK_UM<<"/I"<<INC_SDK_UCRT;

    argu<<"/D"<<"NDEBUG"<<"/D"<<"AMIDLL_EXPORTS"<<"/D"<<"_WINDOWS"<<"/D"<<"_USRDLL"<<"/D"<<"_WINDLL"<<"/D"<<"_UNICODE";
    argu<<"/Gm-"<<"/EHsc"<<"/MD"<<"/GS"<<"/Gy"<<"/fp:precise"<<"/permissive-"<<"/Zc:wchar_t"<<"/Zc:forScope"<<"/Zc:inline";
    argu<<"/Fo"+INC_USR+"/x64/Release/"<<"/Gd"<<"/TP"<<"/FC"<<"/errorReport:prompt"<<INC_USR+"/serdes_tx.cpp";

    process->start(cl,argu);
    if(process->waitForFinished()){
        if(process->exitCode()==0){
            ui->textBrowser->append(process->readAllStandardError());
            ui->textBrowser->append(process->readAllStandardOutput());
        }
        else{
            ui->textBrowser->append(process->readAllStandardError());
            ui->textBrowser->append(process->readAllStandardOutput());
        }
    }



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

    compile();

}

void compiler::on_closePushButton_clicked()
{
    this->close();
}

void compiler::on_AMIPushButton_clicked()
{
    generateDll();
}
