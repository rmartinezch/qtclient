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
}

Client::~Client()
{
    delete ui;
}

void Client::requestMessage()
{
    qDebug() << "requestMessage() start ...";
}

void Client::readMessage()
{
    qDebug() << "readMessage() start ...";
}

void Client::showError()
{
    qDebug() << "showError() start ...";
}
