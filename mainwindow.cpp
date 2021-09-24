#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include <QDebug>
#include <QFileDialog>

using namespace QXlsx;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->centralWidget()->setStyleSheet("background: #f0f0f0;" );

    Document xlsxR("Test1.xlsx");
        if (xlsxR.load())
        {
            int num_col = xlsxR.dimension().lastColumn();
            int num_row = xlsxR.dimension().lastRow();

            for(int row = 1; row <= num_row; row++)
            {
                for(int col = 1; col <= num_col; col++)
                {
                    Cell* cell = xlsxR.cellAt(row, col);
                    if ( cell != NULL )
                    {
                        QVariant var = cell->readValue();
                        qDebug() << var;
                    }
                }
            }
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_Admissory_triggered()
{
    About abt;
    abt.exec();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_cmdAdd_clicked()
{
   //ui->step1->setStyleSheet("#step1{ background-color: rgba(255,255,255,0.5); }");
}

