

void task4() {
    std::string path;
    std::cout << "Enter the file path:" << std::endl;
    std::cin >> path;
    std::ifstream ifs(path, std::ios::binary);

    while (!ifs.is_open()) {
        std::cout << "Wrong path. Try again:" << std::endl;
        std::cin >> path;
        ifs.open(path, std::ios::binary);
    }

    bool isValidPath = path.substr(path.find('.')) == ".png";

    char mark, p, n, g;
    ifs >> mark >> p >> n >> g;
    bool isValidBytes = (int) mark == -119 && p == 'P' && n == 'N' && g == 'G';

    if (isValidPath && isValidBytes)
        std::cout << "The file is a PNG" << std::endl;
    else
        std::cout << "The file is not a PNG" << std::endl;
    ifs.close();
}
