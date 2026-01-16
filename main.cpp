#include "ConsoleLogger.hpp"
#include "TimestampDecorator.hpp"
#include "EncryptionDecorator.hpp"
#include "FileLoggerDecorator.hpp"
#include <iostream>
#include <fstream>

// Вспомогательный "пустой" логгер для записи только в файл
class NullLogger : public Logger {
public:
    void log(const std::string&) override {}
};

int main() {
    // Очистка файлов
    std::ofstream("output1.txt").close();
    std::ofstream("output2.txt").close();
    std::ofstream("output3.txt").close();

    std::cout << "=== Демонстрация системы логирования ===\n\n";

    // 1. Только консоль
    std::cout << "1. Только консоль:\n";
    auto logger1 = std::make_unique<ConsoleLogger>();
    logger1->log("Простое сообщение");
    std::cout << "\n";

    // 2. Временная метка + консоль
    std::cout << "2. Консоль с временной меткой:\n";
    auto logger2 = std::make_unique<TimestampDecorator>(
        std::make_unique<ConsoleLogger>()
    );
    logger2->log("Сообщение с временем");
    std::cout << "\n";

    // 3. Шифрование + консоль
    std::cout << "3. Зашифрованное сообщение в консоль:\n";
    auto logger3 = std::make_unique<EncryptionDecorator>(
        std::make_unique<ConsoleLogger>(), 5
    );
    logger3->log("Secret message");
    std::cout << "\n";

    // 4. Время + шифрование + консоль
    std::cout << "4. Время + шифрование + консоль:\n";
    auto logger4 = std::make_unique<TimestampDecorator>(
        std::make_unique<EncryptionDecorator>(
            std::make_unique<ConsoleLogger>(), 3
        )
    );
    logger4->log("Confidential data");
    std::cout << "\n";

    // 5. Всё вместе: время + шифрование + консоль + файл
    std::cout << "5. Всё вместе: время + шифрование + консоль + файл:\n";
    auto logger5 = std::make_unique<FileLoggerDecorator>(
        std::make_unique<TimestampDecorator>(
            std::make_unique<EncryptionDecorator>(
                std::make_unique<ConsoleLogger>(), 4
            )
        ),
        "output1.txt"
    );
    logger5->log("Top secret report");
    std::cout << "(сообщение также записано в output1.txt)\n\n";

    // 6. Только в файл
    std::cout << "6. Только в файл:\n";
    auto logger6 = std::make_unique<FileLoggerDecorator>(
        std::make_unique<NullLogger>(),
        "output2.txt"
    );
    logger6->log("Только в файл");
    std::cout << "(записано в output2.txt)\n\n";

    // 7. Файл + временная метка
    std::cout << "7. Файл + временная метка:\n";
    auto logger7 = std::make_unique<FileLoggerDecorator>(
        std::make_unique<TimestampDecorator>(
            std::make_unique<NullLogger>()
        ),
        "output3.txt"
    );
    logger7->log("Лог с временем только в файл");
    std::cout << "(записано в output3.txt)\n";

    return 0;
}