
void cutt_off(char *s) {
    int spacePos = 0;
    for (int i = 99; i >= 0; i--) {
        if (s[i] == ' ') {
            s[i] = 0;
            break;
        }
    }
}

void task2() {
    std::string path;
    std::cout << "Enter the file path:" << std::endl;
    std::cin >> path;
    std::ifstream overview;
    overview.open(path, std::ios::binary);

    while (!overview.is_open()) {
        std::cout << "Wrong path. Try again:" << std::endl;
        std::cin >> path;
        overview.open(path, std::ios::binary);
    }

    while(!overview.eof()) {
        char buffer[2];
        overview.read(buffer, sizeof(buffer) - 1);
        buffer[1] = 0;
        std::cout << buffer;
    }
    overview.close();
}
