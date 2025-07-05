#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;


    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == FTDI6001_vid ||
                                                    FTDI6010_vid ||
                                                    FTDI6011_vid ||
                                                    FTDI6014_vid ||
                                                    FTDI6015_vid ||
                                                    FTDI6031_vid ||
                                                    counterfeitFT232_vid ||
                                                    CH340_vid ||
                                                    CH341_0_vid ||
                                                    CH341_1_vid ||
                                                    CP210x_0_vid ||
                                                    CP210x_1_vid ||
                                                    CP210x_2_vid ||
                                                    CP210x_3_vid ||
                                                    CP210x_4_vid ||
                                                    CP210x_5_vid ||
                                                    CP210x_6_vid ||
                                                    PL2303_0_vid ||
                                                    PL2303_1_vid ||
                                                    PL2303_2_vid ||
                                                    PL2303_3_vid ||
                                                    MCP2221_0_vid ||
                                                    MCP2221_1_vid ||
                                                    MCP2221_2_vid ||
                                                    MCP2221_3_vid ||
                                                    MCP2221_4_vid ||
                                                    MCP2221_5_vid ||
                                                    MCP2221_6_vid ||
                                                    MCP2221_7_vid ||
                                                    MCP2221_8_vid ||
                                                    CY7C65213_vid ||
                                                    HT42B534_vid)
            {
                if(serialPortInfo.productIdentifier() == FTDI6001_pid ||
                                                         FTDI6010_pid ||
                                                         FTDI6011_pid ||
                                                         FTDI6014_pid ||
                                                         FTDI6015_pid ||
                                                         FTDI6031_pid ||
                                                         counterfeitFT232_pid ||
                                                         CH340_pid ||
                                                         CH341_0_pid ||
                                                         CH341_1_pid ||
                                                         CP210x_0_pid ||
                                                         CP210x_1_pid ||
                                                         CP210x_2_pid ||
                                                         CP210x_3_pid ||
                                                         CP210x_4_pid ||
                                                         CP210x_5_pid ||
                                                         CP210x_6_pid ||
                                                         PL2303_0_pid ||
                                                         PL2303_1_pid ||
                                                         PL2303_2_pid ||
                                                         PL2303_3_pid ||
                                                         MCP2221_0_pid ||
                                                         MCP2221_1_pid ||
                                                         MCP2221_2_pid ||
                                                         MCP2221_3_pid ||
                                                         MCP2221_4_pid ||
                                                         MCP2221_5_pid ||
                                                         MCP2221_6_pid ||
                                                         MCP2221_7_pid ||
                                                         MCP2221_8_pid ||
                                                         CY7C65213_pid ||
                                                         HT42B534_pid)
                {
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available){
        // open and configure the port
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        // give error message if not available
        QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
    }
}

Dialog::~Dialog()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}

void Dialog::on_radioButton_0_clicked()
{
    Dialog::updateSwitch(QString("0"));
}

void Dialog::on_radioButton_1_clicked()
{
    Dialog::updateSwitch(QString("1"));
}

void Dialog::on_radioButton_2_clicked()
{
    Dialog::updateSwitch(QString("2"));
}

void Dialog::on_radioButton_3_clicked()
{
    Dialog::updateSwitch(QString("3"));
}

void Dialog::on_radioButton_4_clicked()
{
    Dialog::updateSwitch(QString("4"));
}

void Dialog::on_radioButton_5_clicked()
{
    Dialog::updateSwitch(QString("5"));
}

void Dialog::on_radioButton_6_clicked()
{
    Dialog::updateSwitch(QString("6"));
}

void Dialog::updateSwitch(QString command)
{
    if(arduino->isWritable()){
        arduino->write(command.toStdString().c_str());

    }else{
        qDebug() << "Couldn't write to serial!";
    }
}
