#include"ui.h"

ui::ui(){
    btn_send = new QPushButton("send");
    btn_connect = new QPushButton("connect");
    led_ip = new QLineEdit;
    led_port = new QLineEdit;
    led_receive_data = new QTextEdit;
    led_send_data = new QLineEdit;
    label_ip = new QLabel("IP");
    label_port = new QLabel("Port");
    hlayout_up = new QHBoxLayout;
    hlayout_down = new QHBoxLayout;
    vlayout = new QVBoxLayout;
    _socket = new QTcpSocket(this);

    led_receive_data->setFixedHeight(400);
    led_receive_data->setFixedWidth(400);
    led_receive_data->setReadOnly(true);
    led_send_data->setDisabled(true);
    btn_send->setDisabled(true);

    hlayout_up->addWidget(label_ip);
    hlayout_up->addWidget(led_ip);
    hlayout_up->addWidget(label_port);
    hlayout_up->addWidget(led_port);
    hlayout_up->addWidget(btn_connect);
    hlayout_down->addWidget(led_send_data);
    hlayout_down->addWidget(btn_send);
    vlayout->addLayout(hlayout_up);
    vlayout->addWidget(led_receive_data);
    vlayout->addLayout(hlayout_down);
    window.setLayout(vlayout);

    connect(btn_connect, SIGNAL(clicked(bool)), this, SLOT(newConnection()));
    connect(btn_send, SIGNAL(clicked()), this, SLOT(send_data()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void ui::show(){
    window.show();
}

void ui::newConnection(){
    led_ip->setDisabled(true);
    led_port->setDisabled(true);
    QHostAddress ip(led_ip->text());
    QString port = led_port->text();
    _socket->connectToHost(ip, port.toInt());
    if(_socket->waitForConnected(3000)){
        led_send_data->setEnabled(true);
        btn_send->setEnabled(true);
    }
}

void ui::send_data(){
    QString str = led_send_data->text();
    QByteArray data = led_send_data->text().toUtf8();
    _socket->write(data);
    led_receive_data->append("client: " + str);
    led_send_data->clear();
}

void ui::readData(){
    QByteArray ba = _socket->readAll();
    QString str(ba);
    led_receive_data->append("server: " + str);
}
