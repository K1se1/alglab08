#include <iostream>
#include "InvIndex.hpp"
#include<filesystem> // для нахождения названий файлов в директории


std::set<std::string> bruteforce_search(const std::string& key, const std::vector<std::string>&  paths) // функция с грубым поиском
{
    std::set<std::string> docs;
    std::string word;
    for(const auto& path: paths)
    {
        std::ifstream file(path);
         while(std::getline(file, word, ' '))
        {
            InvIndex::normalize(word);
            if(word == key)
            {
                docs.insert(path);
                continue;
            }
        }
    }
    return docs;
}


int main(int, char**){
    InvIndex books;
    std::string folder = "C:\\AlgLab\\Lab08\\docs"; // здесь указать путь к папке с книгами
    std::vector<std::string> paths;
    // вот здесь цикл для поиска путей файлов в директории
    for (const auto & entry : std::filesystem::directory_iterator(folder))
        paths.push_back(std::string(entry.path().string()));
    books.add_files(paths); // добавляем наши книги в класс 
    // Поиск слова "you" с помощью инвентированных индексов
    for(const auto& doc: books["you"])
    {
        std::cout << doc << "\n";
    }
    std::cout << "\n";
    // с помощью грубого поиска
    for(const auto& doc: bruteforce_search("you", paths))
    {
        std::cout << doc << "\n";
    }

}
