#include "mainwindow.h"
#include "./ui_mainwindow.h"

double PowerUsage, PowerCost, HourCost, MinCost, SecCost, ExpHourCost,
    ExpMinCost, ExpSecCost, ExpElectricityCost, FilamentCost, FilamentUsage,
    TotFilamentCost, ExpTotCost, Wattage;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_PowerUsageEdit_editingFinished() {
    Wattage = ui->PowerUsageEdit->value();
    PowerUsage = Wattage * ui->HourBox->value() / 1000;
}

void MainWindow::on_PowerCostEdit_editingFinished() {
    PowerCost = ui->PowerCostEdit->value();
    HourCost = PowerCost * PowerUsage;
    MinCost = HourCost / 60;
    SecCost = MinCost / 60;
}

void MainWindow::on_HourBox_editingFinished() {
    ExpHourCost = HourCost * ui->HourBox->value();
}

void MainWindow::on_MinBox_editingFinished() {
    ExpMinCost = MinCost * ui->MinBox->value();
}

void MainWindow::on_SecBox_editingFinished() {
    ExpSecCost = SecCost * ui->SecBox->value();
}

void MainWindow::on_FilamentCostEdit_editingFinished() {
    FilamentCost = ui->FilamentCostEdit->value();
}

void MainWindow::on_FilamentUsageEdit_editingFinished() {
    FilamentUsage = ui->FilamentUsageEdit->value();
}

void MainWindow::on_Calculate_clicked() {
    // Electricity calc
    PowerUsage = Wattage * ui->HourBox->value() / 1000;
    PowerCost = ui->PowerCostEdit->value();
    HourCost = PowerCost * PowerUsage;
    MinCost = HourCost / 60;
    SecCost = MinCost / 60;
    ExpHourCost = HourCost * ui->HourBox->value();
    ExpMinCost = MinCost * ui->MinBox->value();
    ExpSecCost = SecCost * ui->SecBox->value();
    ExpElectricityCost = ExpHourCost + ExpMinCost + ExpSecCost;
    QString ExpElectricityCostStr = QString::number(ExpElectricityCost);
    ui->ExpectedElectricityCostEdit->setText(ExpElectricityCostStr);
    QString ExpPowerUsageStr = QString::number(PowerUsage);
    ui->ExpectedPowerUsageEdit->setText(ExpPowerUsageStr);

    // Filament Calc
    FilamentCost = ui->FilamentCostEdit->value();
    FilamentUsage = ui->FilamentUsageEdit->value();
    TotFilamentCost = FilamentCost * FilamentUsage;
    QString ExpFilamentCostStr = QString::number(TotFilamentCost);
    ui->ExpectedFilamentCostEdit->setText(ExpFilamentCostStr);

    // Total Cost Calc
    ExpTotCost = ExpElectricityCost + TotFilamentCost;
    QString ExpTotCostStr = QString::number(ExpTotCost);
    ui->TotalPrintCostEdit->setText(ExpTotCostStr);
}
