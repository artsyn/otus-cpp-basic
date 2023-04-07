#include "tictactoe.hpp"
#include <QPainter>
#include <QMouseEvent>
#include <array>
#include <QDebug>

TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent) {
    initBoard();
}

void TicTacToeWidget::initBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_board[i][j] = CellState::Empty;
        }
    }
    m_currentPlayer = CellState::Cross;
}

int TicTacToeWidget::cellWidth() const {
    return width() / 3;
}

int TicTacToeWidget::cellHeight() const {
    return height() / 3;
}

void TicTacToeWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    for (int i = 1; i < 3; ++i) {
        painter.drawLine(cellWidth() * i, 0, cellWidth() * i, height());
        painter.drawLine(0, cellHeight() * i, width(), cellHeight() * i);
    }

    QFont font = painter.font();
    font.setPointSize(cellWidth() / 2); // размер шрифта
    painter.setFont(font);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            CellState state = m_board[i][j];
            if (state != CellState::Empty) {
                QRect cellRect(i * cellWidth(), j * cellHeight(), cellWidth(), cellHeight());
                painter.drawText(cellRect, Qt::AlignCenter, state == CellState::Cross ? "X" : "O");
            }
        }
    }
}

void TicTacToeWidget::mousePressEvent(QMouseEvent *event) {
    
    int row = event->x() / cellWidth();
    int col = event->y() / cellHeight();
    qDebug() << "Player clicked: " << row << ", " << col;

    if (m_board[row][col] == CellState::Empty) {
        m_board[row][col] = m_currentPlayer;

        if (checkWin(m_currentPlayer)) {
            emit gameOver(m_currentPlayer);
        } else {
            m_currentPlayer = (m_currentPlayer == CellState::Cross) ? CellState::Circle : CellState::Cross;
            emit currentPlayerChanged(m_currentPlayer);
        }

        update();
    }
}

bool TicTacToeWidget::checkWin(CellState player) const {
    qDebug() << "Checking win for player: " << (player == CellState::Cross ? "Cross" : "Circle");

    for (int i = 0; i < 3; ++i) {
        if ((m_board[i][0] == player && m_board[i][1] == player && m_board[i][2] == player) ||
            (m_board[0][i] == player && m_board[1][i] == player && m_board[2][i] == player)) {
            qDebug() << "Win in row or column";
            return true;
        }
    }

    if ((m_board[0][0] == player && m_board[1][1] == player && m_board[2][2] == player) ||
        (m_board[0][2] == player && m_board[1][1] == player && m_board[2][0] == player)) {
        qDebug() << "Win in diagonal";
        return true;
    }

    return false;
}

