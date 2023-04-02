#include <iostream>
#include <limits>
#include <vector>
#include <sstream>

class IStatistics {
public:
    virtual ~IStatistics() noexcept {}

    virtual void update(double next) = 0;
    virtual double eval() const = 0;
    virtual const char* name() const = 0;
};

class Min : public IStatistics {
public:
    Min() : m_min{std::numeric_limits<double>::max()} {}

    void update(double next) override {
        if (next < m_min) {
            m_min = next;
        }
    }

    double eval() const override {
        return m_min;
    }

    const char* name() const override {
        return "min";
    }

private:
    double m_min;
};

class Max : public IStatistics {
public:
    Max() : m_max{std::numeric_limits<double>::lowest()} {}

    void update(double next) override {
        if (next > m_max) {
            m_max = next;
        }
    }

    double eval() const override {
        return m_max;
    }

    const char* name() const override {
        return "max";
    }

private:
    double m_max;
};

class Mean : public IStatistics {
public:
    Mean() : count_{0}, sum_{0.0} {}

    void update(double next) override {
        ++count_;
        sum_ += next;
    }

    double eval() const override {
        return sum_ / count_;
    }

    const char* name() const override {
        return "mean";
    }

private:
    int count_;
    double sum_;
};

class Std : public IStatistics {
public:
    Std() : count_{0}, sum_{0.0}, sumsq_{0.0} {}

    void update(double next) override {
        ++count_;
        sum_ += next;
        sumsq_ += next * next;
    }

    double eval() const override {
        double mean = sum_ / count_;
        double var = (sumsq_ - count_ * mean * mean) / count_ ;
        return std::sqrt(var);
    }

    const char* name() const override {
        return "std";
    }

private:
    int count_;
    double sum_;
    double sumsq_;
};

int main() {
    const size_t statistics_count = 4;
    IStatistics* statistics[statistics_count];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Mean{};
    statistics[3] = new Std{};

    std::vector<double> values;

//     std::cout << "Enter a sequence of numbers in column (e.g 1 ENTER 2 ENTER ... and type 'q' to finish): " << std::endl;

//     std::string input;
//     while (std::getline(std::cin, input)) {
//         if (input == "q") {
//             break;
//         }
//     double val;
//     std::stringstream ss(input);
//     if (ss >> val) {
//         values.push_back(val);
//     } else {
//         std::cout << "Invalid input. Please enter a number or 'q' to finish." << std::endl;
//     }
// }

    std::cout << "Enter a sequence of numbers separated by spaces: " << std::endl;

    std::string input_line;
    std::getline(std::cin, input_line);
    std::istringstream input_stream(input_line);

    double val;
    while (input_stream >> val) {
        values.push_back(val);
    }


    
    if (values.size() > 0) {
        for (size_t i = 0; i < statistics_count; ++i) {
            for (const auto& value : values) {
                statistics[i]->update(value);
            }
            std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
        }
    } else {
        std::cout << "No values were entered." << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics[i];
    }
    std::cin.get();
    return 0;
}