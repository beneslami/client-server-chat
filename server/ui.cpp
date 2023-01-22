#include "ui.h"

ui::ui()
{
    btn = new QPushButton("send");
    bar = new QProgressBar;
    led_send_data = new QLineEdit;
    led_receive_data = new QTextEdit;
    hlayout = new QHBoxLayout;
    vlayout = new QVBoxLayout;
    _server = new QTcpServer;
    _socket = new QTcpSocket;

    led_receive_data->setFixedHeight(400);
    led_receive_data->setFixedWidth(400);
    led_receive_data->setReadOnly(true);
    bar->setMaximum(0);
    bar->setMinimum(0);
    _server->listen(QHostAddress::Any, 2000);
    btn->setDisabled(true);
    led_send_data->setDisabled(true);

    hlayout->addWidget(led_send_data);
    hlayout->addWidget(btn);
    vlayout->addWidget(bar);
    vlayout->addWidget(led_receive_data);
    vlayout->addLayout(hlayout);
    window.setLayout(vlayout);
    connect(btn, SIGNAL(clicked()), this, SLOT(getSendText()));
    connect(_server, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void ui::show(){
    window.show();
}

void ui::getSendText(){
    QString str = led_send_data->text();
    _socket->write(led_send_data->text().toUtf8());
    led_receive_data->append("Server: " + str);
    led_send_data->clear();
}

void ui::newConnection(){
    btn->setEnabled(true);
    led_send_data->setEnabled(true);
    bar->hide();
    _socket = _server->nextPendingConnection();
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void ui::readData(){
    QByteArray ba = _socket->readAll();
    QString str(ba);
    led_receive_data->append("client: " + str);
}
