#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow window;
  window.resize(300, 190);
  window.setWindowTitle("Plus minus");
  window.show();
  return app.exec();
}
