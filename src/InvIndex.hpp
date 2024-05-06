#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

class InvIndex
{
    private:
    std::map<std::string, std::set<std::string>>* words_map; // словарь где ключи - строки, а значения - множество строк(для уникальности элементов)
    public:
    static void normalize(std::string& str); // нормализуем слова(приводим к строчным буквам, удаляем числа и знаки препинания) static для использования вне класса(нужно для функицц bruteforce)
    InvIndex(); // конструктор по умолчанию
    InvIndex(const std::vector<std::string>& paths); // конструктор, куда подаются пути файлов
    ~InvIndex(); // деструктор
    void add_files(const std::vector<std::string>& paths); //добавляем какие-то файлы в наш словарь
    std::set<std::string> operator[](const std::string& key); // перегружаем [] для сохранения инкапсуляции

};


