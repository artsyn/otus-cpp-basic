#include "mainwindow.hpp"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    m_tictactoe = new TicTacToeWidget(this);
    setCentralWidget(m_tictactoe);
    setFixedSize(300, 300);
    setWindowTitle("Tic Tac Toe");
}
