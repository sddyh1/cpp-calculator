#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enums.h"

#include <QString>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");

    connect(ui->cmb_controller, &QComboBox::currentIndexChanged,
            this, &MainWindow::onCurrentIndexChanged);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetInputText(const std::string& text) {
    ui->l_result->setStyleSheet("");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string& text) {
    ui->l_result->setStyleSheet("color: red;");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetFormulaText(const std::string& text) {
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string& text) {
    ui->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string>& key){
    if (key == std::nullopt) {
        ui->tb_extra->hide();
        return;
    }
    ui->tb_extra->show();
    ui->tb_extra->setText(QString::fromStdString(key.value()));
}

void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb) {
    digit_cb_ = cb;
}

void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb){
    operation_cb_ = cb;
}

void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb) {
    control_cb_ = cb;
}

void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb) {
    controller_cb_ = cb;
}

void MainWindow::onCurrentIndexChanged(int index){
    QString type = ui->cmb_controller->currentText();

    if (type == "double") {
        controller_cb_(ControllerType::DOUBLE);
    } else if (type == "float") {
        controller_cb_(ControllerType::FLOAT);
    } else if (type == "uint8_t") {
        controller_cb_(ControllerType::UINT8_T);
    } else if (type == "int") {
        controller_cb_(ControllerType::INT);
    } else if (type == "int64_t") {
        controller_cb_(ControllerType::INT64_T);
    } else if (type == "size_t") {
        controller_cb_(ControllerType::SIZE_T);
    } else if (type == "Rational") {
        controller_cb_(ControllerType::RATIONAL);
    }
}

void MainWindow::on_tb_zero_clicked() {
    if(digit_cb_){
        digit_cb_(0);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_one_clicked()
{
    if(digit_cb_){
        digit_cb_(1);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_two_clicked()
{
    if(digit_cb_){
        digit_cb_(2);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_three_clicked()
{
    if(digit_cb_){
        digit_cb_(3);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_four_clicked()
{
    if(digit_cb_){
        digit_cb_(4);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_five_clicked()
{
    if(digit_cb_){
        digit_cb_(5);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_six_clicked()
{
    if(digit_cb_){
        digit_cb_(6);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_seven_clicked()
{
    if(digit_cb_){
        digit_cb_(7);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_eight_clicked()
{
    if(digit_cb_){
        digit_cb_(8);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_nine_clicked()
{
    if(digit_cb_){
        digit_cb_(9);
    }
    else{
        qDebug()<<"digit is not set";
    }
}

void MainWindow::on_tb_add_clicked()
{
    if(operation_cb_){
        operation_cb_(Operation::ADDITION);
    }
    else{
        qDebug()<<"operation is not set";
    }
}

void MainWindow::on_tb_substract_clicked()
{
    if(operation_cb_){
        operation_cb_(Operation::SUBTRACTION);
    }
    else{
        qDebug()<<"operation is not set";
    }
}

void MainWindow::on_tb_multiplicate_clicked()
{
    if(operation_cb_){
        operation_cb_(Operation::MULTIPLICATION);
    }
    else{
        qDebug()<<"operation is not set";
    }
}

void MainWindow::on_tb_divide_clicked()
{
    if(operation_cb_){
        operation_cb_(Operation::DIVISION);
    }
    else{
        qDebug()<<"operation is not set";
    }
}

void MainWindow::on_tb_power_clicked()
{
    if(operation_cb_){
        operation_cb_(Operation::POWER);
    }
    else{
        qDebug()<<"operation is not set";
    }
}

void MainWindow::on_tb_equal_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::EQUALS);
    }
    else{
        qDebug()<<"control is not set";
    }
}

void MainWindow::on_tb_reset_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::CLEAR);
    }
    else{
        qDebug()<<"control is not set";
    }
}

void MainWindow::on_tb_backspace_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::BACKSPACE);
    }
    else{
        qDebug()<<"control is not set";
    }
}

void MainWindow::on_tb_extra_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::EXTRA_KEY);
    }
    else{
        qDebug()<<"control is not set";
    }
}

void MainWindow::on_tb_negate_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::PLUS_MINUS);
    }
    else{
        qDebug()<<"control is not set";
    }
}

void MainWindow::on_tb_mc_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::MEM_CLEAR);
    }
    else{
        qDebug()<<"control is not set";
    }
}

void MainWindow::on_tb_mr_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::MEM_LOAD);
    }
    else{
        qDebug()<<"control is not set";
    }
}

void MainWindow::on_tb_ms_clicked()
{
    if(control_cb_){
        control_cb_(ControlKey::MEM_SAVE);
    }
    else{
        qDebug()<<"control is not set";
    }
}

