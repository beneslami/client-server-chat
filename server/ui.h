#ifndef UI_H
#define UI_H
#include<QWidget>
#include<QLineEdit>
#include<QTextEdit>
#include<QPushButton>
#include<QProgressBar>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTcpServer>
#include<QTcpSocket>
class ui : public QObject
{
    Q_OBJECT
private:
    QWidget window;
    QPushButton *btn;
    QProgressBar *bar;
    QLineEdit *led_send_data;
    QTextEdit *led_receive_data;
    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;
    QTcpServer *_server;
    QTcpSocket *_socket;

public:
    ui();
    void show();
private slots:
    void getSendText();
    void newConnection();
    void readData();
};
#endif // UI_H
