#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    connect(ui->pBtn_Close, &QAbstractButton::clicked, this, &QWidget::close);
    // Procesar datos recibidos
    connect(clientSocket, &QIODevice::readyRead, this, &Client::readMessage);
    // Botón conectar
    connect(ui->pBtn_Connect, &QAbstractButton::clicked, this, &Client::requestMessage);
    // Capturando los errores de comunicación
}

Client::~Client()
{
    delete ui;
}

/**
 * @brief Client::requestMessage
 * Este slot inicia la comunicación con el Servidor
 * y se solicita un mensaje
 */
void Client::requestMessage()
{
    qDebug() << "requestMessage() start ...";
    QString ipAddress = ui->lEdt_ip->text();
    QString port = ui->lEdt_port->text();
    qDebug() << "ip: " << ipAddress << ", port: " << port;

    clientSocket->connectToHost(ipAddress, port.toInt());
    qDebug() << "requestMessage() end ...";
}

/**
 * @brief Client::readMessage
 * Este slot inicia le lectura del mensaje que ha llegado al cliente
 */
void Client::readMessage()
{
    qDebug() << "readMessage() start ...";
    in.startTransaction();
    QString message;
    in >> message;
    if (!in.commitTransaction()) {
        qDebug() << "Error in datastream";
        return;
    }
    qDebug() << "message: " << message;
    ui->lbl_Message->setText(message);
    qDebug() << "readMessage() end ...";
}

void Client::showError()
{
    qDebug() << "showError() start ...";
}
