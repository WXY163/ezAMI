#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <iostream>
#include <QMessageBox>
#include <QProcess>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    toolBar = new QToolBar;
    toolBar->addAction("Excitation");
    toolBar->addAction("Plotting");
    toolBar->addAction("Model");
    this->setWindowTitle(tr("ezAMI1.0"));
    this->addToolBar(toolBar);

    plot = new plotting;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete plot;
}

void MainWindow::on_simulateButton_clicked()
{

    if (QLibrary::isLibrary("ami.dll")) {
          ui->statusWindow->append("Simulation is running...");
          QLibrary lib("ami.dll");
          lib.load();
          if (!lib.isLoaded()) {
            qDebug() << lib.errorString();
          }

          if (lib.isLoaded()) {

            ui->statusWindow->append("success");

             typedef long (*FunctionPrototype)(double *impulse_matrix,
                                               long row_size,
                                               long aggressors,
                                               double sample_interval,
                                               double bit_time,
                                               char **AMI_parameters_in,
                                               char **AMI_parameters_out,
                                               void **AMI_memory_handle,
                                               char **msg);

            //FunctionPrototype AMI_GetWave = (FunctionPrototype)lib.resolve("AMI_GetWave");
             FunctionPrototype AMI_Init = (FunctionPrototype)lib.resolve("AMI_Init");
            // if null means the symbol was not loaded

            if (AMI_Init){
                double *impulse_matrix = nullptr;
                long row_size = 0;
                long aggressors = 0;
                double sample_interval = 1.0;
                double bit_time =1.0;
                char **AMI_parameters_in = nullptr;
                char **AMI_parameters_out = nullptr;
                void **AMI_memory_handle = nullptr;
                char **msg = nullptr;
                long result = AMI_Init(impulse_matrix,
                                       row_size,aggressors,
                                       sample_interval,
                                       bit_time,
                                       AMI_parameters_in,
                                       AMI_parameters_out,
                                       AMI_memory_handle,
                                       msg);
                ui->statusWindow->append(QString::number(result));
            }
            else {
                ui->statusWindow->append("Cannot use add function Add in dll");
            }

          }
        }

    //plot->show();


}
void MainWindow::on_generateAmiButton_clicked()
{
    ui->statusWindow->append("AMI model generation is running...");
    QMessageBox msgBox;
    msgBox.setText("I am still working on it ....");
    msgBox.exec();

}


void MainWindow::on_compileButton_clicked()
{
    QProcess process;
    QString program = "gcc";
    QStringList argu, argu1;
    argu<<"-c"<<"-o"<<"/Research/ezAMI/AMI/ami.o"<<"F:/Research/ezAMI/AMI/ami.cpp"<<"-D"<<"ADD_EXPORTS";
    argu1<<"-o"<<"F:/Research/ezAMI/ezAMI/debug/ami.dll"<<"-s"<<"-shared"<<"F:/Research/ezAMI/AMI/ami.o"<<"-Wl,--subsystem,windows";
    //QProcess::execute("gcc -c -o F:/Research/C++/exampe.o F:/Research/C++/example.cpp -D ADD_EXPORTS");
    process.start(program,argu);
    if(process.waitForFinished()){
        if(process.exitCode() == 0){
            ui->statusWindow->append(process.readAllStandardOutput());
            process.start(program,argu1);
            if(process.waitForFinished()){
                if(process.exitCode()==0){
                    ui->statusWindow->append(process.readAllStandardOutput());
                    ui->statusWindow->append("Compile finished without error!");
                }
                else {
                    ui->statusWindow->append(process.readAllStandardError());

                }
            }
        }

        else
            ui->statusWindow->append(process.readAllStandardError());
    }
}

void MainWindow::on_saveButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                 "F:/Research/ezAMI/AMI",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    QString fileName = "ami.cpp";
    QString filePath = dir + "/" + fileName;

    QFile cFile(filePath);
    if(cFile.open(QIODevice::ReadWrite)){
        QTextStream stream(&cFile);
        stream<<ui->amiInit->toPlainText();
        stream<<endl;
        stream<<ui->amiGetWave->toPlainText();
        stream<<endl;
        stream<<ui->amiClose->toPlainText();

        cFile.flush();
        cFile.close();
        ui->saveButton->setEnabled(false);
    }
    else {
        QMessageBox::critical(this, tr("Error"), tr("Cannot Save in file"));
         return;
    }

}

void MainWindow::on_amiInit_textChanged()
{
    ui->saveButton->setEnabled(true);
}

void MainWindow::on_amiGetWave_textChanged()
{
    ui->saveButton->setEnabled(true);
}

void MainWindow::on_amiClose_textChanged()
{
    ui->saveButton->setEnabled(true);
}
