/*
 *     ezAMI: IBIS-AMI model generation tool
 *    Copyright (C) 2020
 *   Author: Xinying Wang (xinying@illinois.edu)
 *           Department of Electrical Computer Engineering
 *           University of Illinois at Urbana-Champaign
 *

 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "compiler.h"
#include <QFileDialog>
#include <QMessageBox>



compiler::compiler(QWidget *parent) : QDialog(parent),ui(new Ui::Compiler_Dialog)
{
    ui->setupUi(this);
    process = new QProcess();
    setupPath();
}
compiler::~compiler()
{
    delete process;
}

QString compiler::getSourcePath() const
{
    return projectDirectory;
}

void compiler::compile()
{
    /*
    QString program = "gcc";
    QStringList gccargu1, gccargu2, linkargu;
    gccargu1<<"-c"<<"-o"<<"/Research/ezAMI/AMI/ami.o"<<"F:/Research/ezAMI/AMI/ami.cpp"<<"-D"<<"ADD_EXPORTS";
    gccargu2<<"-c"<<"-o"<<"/Research/ezAMI/AMI/AMI_container.o"<<"F:/Research/ezAMI/AMI/AMI_container.cpp" <<"-D"<<"ADD_EXPORTS";
    linkargu<<"-o"<<"F:/Research/ezAMI/AMI/ami.dll"<<"-s"<<"-shared"<<"F:/Research/ezAMI/AMI/ami.o"<<"/Research/ezAMI/AMI/AMI_container.o"<<"-Wl,--subsystem,windows";
    //QProcess::execute("gcc -c -o F:/Research/C++/exampe.o F:/Research/C++/example.cpp -D ADD_EXPORTS");
    process->start(program,gccargu1);
    if(process->waitForFinished()){
        if(process->exitCode() == 0){
            ui->textBrowser->append(process->readAllStandardOutput());
            process->start(program,gccargu2);
            if(process->waitForFinished()){
                if(process->exitCode()==0)
                {
                    ui->textBrowser->append(process->readAllStandardOutput());
                    ui->textBrowser->append("Compile done!");
                }
                else
                {
                    ui->textBrowser->append(process->readAllStandardOutput());
                    ui->textBrowser->append(process->readAllStandardError());
                    return;

                }
            }
        }

        else
        {

            ui->textBrowser->append(process->readAllStandardError());
            return;
        }


    }
    process->start(program,linkargu);
    if(process->waitForFinished()){
        if(process->exitCode()==0)
        {
            ui->textBrowser->append(process->readAllStandardOutput());
            ui->textBrowser->append("Link finish!");
        }
        else
        {
            ui->textBrowser->append(process->readAllStandardOutput());
            ui->textBrowser->append(process->readAllStandardError());
            ui->textBrowser->append("something wrong");
            return;

        }
    }
    */
    QDir msvcPathDir(msvcPath);
    if(!msvcPathDir.exists())
    {
        QMessageBox::critical(this, "MSVC Compiler Path Error!", "Please Specify correct MSVC path!", "Ok");
        return;
    }

    QDir sdkPathDir(windowsSDKPath);
    if(!sdkPathDir.exists())
    {
        windowsSDKPath = QFileDialog::getExistingDirectory(this,tr("Select Directory"),
                                     tr("C:/Program Files (x86)/Windows Kits/10/Include/"));
    }

    QDir sdkLibPathDir(windowsSDKLibPath);
    if(!sdkLibPathDir.exists())
    {
        windowsSDKLibPath = QFileDialog::getExistingDirectory(this,tr("Select Directory"),
                                     tr("C:/Program Files (x86)/Windows Kits/10/Lib/"));
    }

    QString cl = msvcPath + "/bin/HostX86/x64/cl.exe";
    QString link = msvcPath +"/bin/HostX86/x64/LINK.exe";

    QString INC_VS = msvcPath + "/include";
    QString INC_SDK_SH = windowsSDKPath + "/shared";
    QString INC_SDK_UM = windowsSDKPath + "/um";
    QString INC_SDK_UCRT = windowsSDKPath + "/ucrt";
    QString INC_USR = projectDirectory;


    QString LIB_VS = msvcPath + "/lib/x64";
    QString LIB_SDK = windowsSDKLibPath  + "/um/x64";
    QString LIB_SDK_UCRT = windowsSDKLibPath  + "/ucrt/x64";

    QStringList clargu;

    clargu<<"/c"<<"/I"<<INC_USR<<"/I"<<INC_VS<<"/I"<<INC_SDK_SH<<"/I"<<INC_SDK_UM<<"/I"<<INC_SDK_UCRT;
    clargu<<"/D"<<"NDEBUG"<<"/D"<<"AMIDLL_EXPORTS"<<"/D"<<"_WINDOWS"<<"/D"<<"_USRDLL"<<"/D"<<"_WINDLL"<<"/D"<<"_UNICODE";
    clargu<<"/Gm-"<<"/EHsc"<<"/MD"<<"/GS"<<"/Gy"<<"/fp:precise"<<"/permissive-"<<"/Zc:wchar_t"<<"/Zc:forScope"<<"/Zc:inline";
    clargu<<"/Fo"+ projectDirectory<<"/Gd"<<"/TP"<<"/FC"<<"/errorReport:prompt";
    clargu += sourceFiles;

    QStringList linkargu;

    linkargu<<"/OUT:"+projectDirectory + excutableFile;
    linkargu += excutableObjFiles;
    linkargu<<"/LIBPATH:"+LIB_VS<<"/LIBPATH:"+LIB_SDK<<"/LIBPATH:"+LIB_SDK_UCRT;
    linkargu<<"/DYNAMICBASE"<<"kernel32.lib"<<"user32.lib"<<"gdi32.lib"<<"winspool.lib"<<"comdlg32.lib"<<"advapi32.lib";
    linkargu<<"shell32.lib"<<"ole32.lib"<<"oleaut32.lib"<<"uuid.lib"<<"odbc32.lib"<<"odbccp32.lib"<<"/IMPLIB:"+INC_USR + "/x64/Release/ami.lib";
    linkargu<<"/DLL"<<"/MACHINE:X64"<<"/OPT:REF"<<"/INCREMENTAL:NO"<<"/SUBSYSTEM:WINDOWS"<<"/OPT:ICF"<<"/NXCOMPAT"<<"/ERRORREPORT:PROMPT";
    linkargu<<"/NOLOGO"<<"/TLBID:1";

    process->start(cl,clargu);
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
    process->start(link,linkargu);
    if(process->waitForFinished()){
        if(process->exitCode()==0){
            ui->textBrowser->append(process->readAllStandardError());
            ui->textBrowser->append(process->readAllStandardOutput());
            emit updateProjectArch();
        }
        else{
            ui->textBrowser->append(process->readAllStandardError());
            ui->textBrowser->append(process->readAllStandardOutput());
        }
    }

}

void compiler::generateDll()
{
    QDir msvcPathDir(msvcPath);
    if(!msvcPathDir.exists())
    {
        QMessageBox::critical(this, "MSVC Compiler Path Error!", "Please Specify correct MSVC path!", "Ok");
        return;
    }

    QDir sdkPathDir(windowsSDKPath);
    if(!sdkPathDir.exists())
    {
        windowsSDKPath = QFileDialog::getExistingDirectory(this,tr("Select Directory"),
                                     tr("usually under C:/Program Files (x86)/Windows Kits/10/Include/<YOUR_KERNEL_VERSION>"));
    }

    QDir sdkLibPathDir(windowsSDKLibPath);
    if(!sdkLibPathDir.exists())
    {
        windowsSDKLibPath = QFileDialog::getExistingDirectory(this,tr("Select Directory"),
                                     tr("usually under C:/Program Files (x86)/Windows Kits/10/Lib/<YOUR_KERNEL_VERSION>"));
    }

    QString cl = msvcPath + "/bin/HostX86/x64/cl.exe";
    QString link = msvcPath +"/bin/HostX86/x64/LINK.exe";

    QString INC_VS = msvcPath + "/include";
    QString INC_SDK_SH = windowsSDKPath + "/shared";
    QString INC_SDK_UM = windowsSDKPath + "/um";
    QString INC_SDK_UCRT = windowsSDKPath + "/ucrt";
    QString INC_USR = projectDirectory;


    QString LIB_VS = msvcPath + "/lib/x64";
    QString LIB_SDK = windowsSDKLibPath  + "/um/x64";
    QString LIB_SDK_UCRT = windowsSDKLibPath  + "/ucrt/x64";

    QStringList clargu;

    clargu<<"/c"<<"/I"<<INC_USR<<"/I"<<INC_VS<<"/I"<<INC_SDK_SH<<"/I"<<INC_SDK_UM<<"/I"<<INC_SDK_UCRT;
    clargu<<"/D"<<"NDEBUG"<<"/D"<<"AMIDLL_EXPORTS"<<"/D"<<"_WINDOWS"<<"/D"<<"_USRDLL"<<"/D"<<"_WINDLL"<<"/D"<<"_UNICODE";
    clargu<<"/Gm-"<<"/EHsc"<<"/MD"<<"/GS"<<"/Gy"<<"/fp:precise"<<"/permissive-"<<"/Zc:wchar_t"<<"/Zc:forScope"<<"/Zc:inline";
    clargu<<"/Fo"+ AMIDirectory<<"/Gd"<<"/TP"<<"/FC"<<"/errorReport:prompt";
    clargu += sourceFiles;

    QStringList linkargu;

    linkargu<<"/OUT:"+AMIDirectory + amiDll;
    linkargu += amiObjFiles;
    linkargu<<"/LIBPATH:"+LIB_VS<<"/LIBPATH:"+LIB_SDK<<"/LIBPATH:"+LIB_SDK_UCRT;
    linkargu<<"/DYNAMICBASE"<<"kernel32.lib"<<"user32.lib"<<"gdi32.lib"<<"winspool.lib"<<"comdlg32.lib"<<"advapi32.lib";
    linkargu<<"shell32.lib"<<"ole32.lib"<<"oleaut32.lib"<<"uuid.lib"<<"odbc32.lib"<<"odbccp32.lib"<<"/IMPLIB:"+INC_USR + "/x64/Release/ami.lib";
    linkargu<<"/DLL"<<"/MACHINE:X64"<<"/OPT:REF"<<"/INCREMENTAL:NO"<<"/SUBSYSTEM:WINDOWS"<<"/OPT:ICF"<<"/NXCOMPAT"<<"/ERRORREPORT:PROMPT";
    linkargu<<"/NOLOGO"<<"/TLBID:1";

    process->start(cl,clargu);
    if(process->waitForFinished()){
        if(process->exitCode()==0){
            stdOut = process->readAllStandardError();
            stdErr = process->readAllStandardOutput();
        }
        else{
            stdOut = process->readAllStandardError();
            stdErr = process->readAllStandardOutput();
        }
    }
    process->start(link,linkargu);
    if(process->waitForFinished()){
        if(process->exitCode()==0){
            stdOut += process->readAllStandardError();
            stdErr += process->readAllStandardOutput();
            emit updateProjectArch();
        }
        else{
            stdOut += process->readAllStandardError();
            stdErr += process->readAllStandardOutput();
        }
    }
    generateAmiFile();
}







void compiler::on_buildPushButton_clicked()
{

    compile();

}

void compiler::on_closePushButton_clicked()
{
    this->close();
}

void compiler::amiGeneration()
{
    generateDll();

    emit(sendBuildInfo(stdOut, stdErr));
}

void compiler::updateProjectArch( projectTreeModel *arch)
{
    projectArch = arch;
    QModelIndex rootIndex = projectArch? projectArch->getProjectRoot(): QModelIndex();
    projectTreeItem *projectRootItem = rootIndex.isValid()? static_cast<projectTreeItem*>(rootIndex.internalPointer()) : nullptr;
    if (projectRootItem)
    {
        QString projectPath = projectRootItem->child(0)->data(1).toString();
        projectName = projectRootItem->child(0)->data(0).toString();
        if(!projectName.isNull())
            amiFileName = projectName.split(".").value(0) + ".ami";
        QDir dir = QFileInfo(projectPath).absoluteDir();
        projectDirectory = dir.absolutePath()+ "/";
        AMIDirectory = projectDirectory + "x64/Release/";
        projectTreeItem *sourceCode = projectRootItem->child(1);

        for(auto i = 0; i < sourceCode->childCount(); i++)
        {
            QString sourceFile = sourceCode->child(i)->data(1).toString();
            QString fileName = sourceCode->child(i)->data(0).toString();
            if (fileName.contains(".cpp"))
            {
                sourceFiles<<sourceFile;
                excutableObjFiles<<projectDirectory + fileName.replace(".cpp", ".obj");
                amiObjFiles<<AMIDirectory + fileName.replace(".cpp", ".obj");
            }
        }

    }
}



void compiler::on_gccPathToolButton_clicked()
{
    //need some corrections here in getOpenfileName function
    QString clPath = QFileDialog::getOpenFileName(this,tr("Select cl.exe"),
                                 QDir::currentPath(),"exe files (*.exe)");
    ui->gccPathLineEdit->setText(clPath);
    msvcPath = clPath.split("/bin").value(0);

}

void compiler::generateAmiFile()
{
    QString amiFilePath = AMIDirectory + amiFileName;
    QFile amiFile(amiFilePath);

    if(!amiFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&amiFile);
    out<<"(Rx_PAM"<<endl;
    out<<"\t(Reserved_Parameters"<<endl;
    out<<"\t\t(AMI_Version (Usage Info) (Type String) (Default \"6.0\")(Description \"Valid for AMI Version 5.1 and above\"))"<<endl;
    out<<"\t\t(Init_Returns_Impulse (Usage Info) (Type Boolean) (Default False) (Description \"Init_Returns_Impulse False\"))"<<endl;
    out<<"\t\t(GetWave_Exists (Usage Info) (Type Boolean) (Default True) (Description \"GetWave_Exists True\"))"<<endl;
    out<<"\t\t(Max_Init_Aggressors (Usage Info) (Type Integer) (Default 2147483646) (Description \"Max_Init_Aggressors 2147483646\"))"<<endl;
    out<<"\t\t(Ignore_Bits (Usage Info) (Type Integer) (Default 1000) (Description \"Ignore_Bits\"))"<<endl;
    out<<"\t)"<<endl;
    out<<"\t(Model_Specific"<<endl;
    out<<"\t)"<<endl;
    out<<")";
    amiFile.flush();
    amiFile.close();

}

void compiler::setupPath()
{

    QDir windowsSDKDir(windowsSDKPath);
    QDir windowsSDKLibDir(windowsSDKLibPath);

    windowsSDKPath += windowsSDKDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).last();
    windowsSDKLibPath += windowsSDKLibDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).last();
    QDir vsdir = QDir(vs2019CommunityPath);
    if(vsdir.exists())
    {
        msvcPath = vs2019CommunityPath;
        QDir msvcDir(msvcPath);
        msvcPath += msvcDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).last();
        return;
    }

     vsdir = QDir(vs2019ProfessionalPath);
     if(vsdir.exists())
     {
         msvcPath = vs2019ProfessionalPath;
         QDir msvcDir(msvcPath);
         msvcPath += msvcDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).last();
         return;
     }

     vsdir = QDir(vs2017ProfessionalPath);
     if(vsdir.exists())
     {
         msvcPath = vs2017ProfessionalPath;
         QDir msvcDir(msvcPath);
         msvcPath += msvcDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).last();
         return;
     }
     vsdir = QDir(vs2017CommunityPath);
     if(vsdir.exists())
     {
         msvcPath = vs2017CommunityPath;
         QDir msvcDir(msvcPath);
         msvcPath += msvcDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).last();
         return;
     }
     QMessageBox::warning(this, "specify MSVC path", "Using VS2019 MSVC as default", "Ok");
     return;

}
