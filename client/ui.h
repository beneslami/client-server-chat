#ifndef UI_H
#define UI_H

#include<QWidget>
#include<QLineEdit>
#include<QTextEdit>
#include<QPushButton>
#include<QProgressBar>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTcpSocket>
#include<QLabel>

class ui : public QWidget{
    Q_OBJECT
private:
    QWidget window;
    QPushButton *btn_connect;
    QPushButton *btn_send;
    QLineEdit *led_ip;
    QLineEdit *led_port;
    QLineEdit *led_send_data;
    QTextEdit *led_receive_data;
    QLabel *label_ip, *label_port;
    QHBoxLayout *hlayout_up, *hlayout_down;
    QVBoxLayout *vlayout;
    QTcpSocket *_socket;
private slots:
    void newConnection();
    void send_data();
    void readData();
public:
    ui();
    void show();
};

#endif // UI_H
