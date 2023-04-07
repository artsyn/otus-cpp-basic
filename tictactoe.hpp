#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <array>

class TicTacToeWidget : public QWidget {
    Q_OBJECT

public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);
    void initBoard();

    enum CellState {
        Empty,
        Cross,
        Circle
    };

    bool checkWin(CellState player) const;

signals:
    void gameOver(CellState winner);
    void currentPlayerChanged(CellState currentPlayer);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    std::array<std::array<CellState, 3>, 3> m_board;
    CellState m_currentPlayer;

    int cellWidth() const;
    int cellHeight() const;
};

#endif // TICTACTOE_H
