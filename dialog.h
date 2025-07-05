#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_radioButton_0_clicked();
    void on_radioButton_1_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();
    void on_radioButton_5_clicked();
    void on_radioButton_6_clicked();

    void updateSwitch(QString);

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;

    // Arduino Uno vendor and product IDs

    static const quint16 FTDI6001_vid = 1027;
    static const quint16 FTDI6001_pid = 24577;

    static const quint16 FTDI6010_vid = 1027;
    static const quint16 FTDI6010_pid = 24592;

    static const quint16 FTDI6011_vid = 1027;
    static const quint16 FTDI6011_pid = 24593;

    static const quint16 FTDI6014_vid = 1027;
    static const quint16 FTDI6014_pid = 24596;

    static const quint16 FTDI6015_vid = 1027;
    static const quint16 FTDI6015_pid = 24597;

    static const quint16 FTDI6031_vid = 1027;
    static const quint16 FTDI6031_pid = 24625;

    static const quint16 counterfeitFT232_vid = 1027;
    static const quint16 counterfeitFT232_pid = 0;

    static const quint16 CH340_vid = 6790;
    static const quint16 CH340_pid = 29987;

    static const quint16 CH341_0_vid = 6790;
    static const quint16 CH341_0_pid = 21795;

    static const quint16 CH341_1_vid = 17224;
    static const quint16 CH341_1_pid = 21795;

    static const quint16 CP210x_0_vid = 4292;
    static const quint16 CP210x_0_pid = 32937;

    static const quint16 CP210x_1_vid = 4292;
    static const quint16 CP210x_1_pid = 60000;

    static const quint16 CP210x_2_vid = 4292;
    static const quint16 CP210x_2_pid = 60001;

    static const quint16 CP210x_3_vid = 4292;
    static const quint16 CP210x_3_pid = 60016;

    static const quint16 CP210x_4_vid = 4292;
    static const quint16 CP210x_4_pid = 60017;

    static const quint16 CP210x_5_vid = 4292;
    static const quint16 CP210x_5_pid = 60032;

    static const quint16 CP210x_6_vid = 4292;
    static const quint16 CP210x_6_pid = 60112;

    static const quint16 PL2303_0_vid = 1659;
    static const quint16 PL2303_0_pid = 8963;

    static const quint16 PL2303_1_vid = 1659;
    static const quint16 PL2303_1_pid = 8964;

    static const quint16 PL2303_2_vid = 1659;
    static const quint16 PL2303_2_pid = 1211;

    static const quint16 PL2303_3_vid = 1659;
    static const quint16 PL2303_3_pid = 43682;

    static const quint16 MCP2221_0_vid = 1240;
    static const quint16 MCP2221_0_pid = 10;

    static const quint16 MCP2221_1_vid = 1240;
    static const quint16 MCP2221_1_pid = 517;

    static const quint16 MCP2221_2_vid = 1240;
    static const quint16 MCP2221_2_pid = 518;

    static const quint16 MCP2221_3_vid = 1240;
    static const quint16 MCP2221_3_pid = 223;

    static const quint16 MCP2221_4_vid = 1240;
    static const quint16 MCP2221_4_pid = 87;

    static const quint16 MCP2221_5_vid = 1240;
    static const quint16 MCP2221_5_pid = 110;

    static const quint16 MCP2221_6_vid = 1240;
    static const quint16 MCP2221_6_pid = 520;

    static const quint16 MCP2221_7_vid = 1240;
    static const quint16 MCP2221_7_pid = 221;

    static const quint16 MCP2221_8_vid = 1240;
    static const quint16 MCP2221_8_pid = 519;

    static const quint16 CY7C65213_vid = 1204;
    static const quint16 CY7C65213_pid = 3;

    static const quint16 HT42B534_vid = 1241;
    static const quint16 HT42B534_pid = 46338;

    QString arduino_port_name;
    bool arduino_is_available;
};
#endif // DIALOG_H


