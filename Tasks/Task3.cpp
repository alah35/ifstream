
int get_sum(const std::vector<int> &v, size_t s = 10) {
    int sum = 0;

    for (int i = 0; i < s; i++) {
        sum += v[i];
    }
    return sum;
}

int get_max_salary_index(const std::vector<int> &v, size_t s = 10) {
    int max = v[0];
    int iMax = 0;
    for (int i; i < s; i++) {
        if (v[i] > max) {
            max = v[i];
            iMax = i;
        }
    }
    return iMax;
}

void task3() {
    std::vector<std::string> names, surnames, dates;
    std::vector<int> salaries;
    std::string path;

    std::cout << "Enter the file path:" << std::endl;
    std::cin >> path;
    std::ifstream table(path);

    while (!table.is_open()) {
     std::cout << "Wrong path. Try again:" << std::endl;
     std::cin >> path;
     table.open(path);
    }

    int salary;
    std::string name, surname, date;
    while (!table.eof()) {
        table >> name >> surname >> salary >> date;
        names.push_back(name);
        surnames.push_back(surname);
        salaries.push_back(salary);
        dates.push_back(date);
    }

    std::cout << "Total paid: " << get_sum(salaries) << std::endl;
    int index = get_max_salary_index(salaries);
    std::cout << "The greatest salary has: " << names[index] << " " << surnames[index] << std::endl;
    table.close();
}
