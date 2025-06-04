#include<iostream>
#include<string>

using namespace std;

struct Element{
    std::string name;
    int age;
    double ves;
    Element* next;
};

class List{
    private:
    Element* head;
    public:
    List(): head(nullptr){}
    void Forward(const std::string& name, int age, double ves){
        Element* newElement = new Element{name,age, ves, head};
        head = newElement;
    }
    void Back(const std::string& name, int age, double ves) {
        Element* newElement = new Element{name, age, ves, nullptr};
        if (!head) {
            head = newElement;
        } else {
            Element* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newElement;
        }
    }
    void After_the_element(const std::string& afterName, const std::string& name, int age, double ves) {
        Element* current = head;
        while (current) {
            if (current->name == afterName) {
                Element* newElement = new Element{name, age, ves, current->next};
                current->next = newElement;
                return;
            }
            current = current->next;
        }
        std::cout << "Элемент " << afterName << " почему-то не нашелся\n";
    }
    void Before_the_element(const std::string& beforeName, const std::string& name, int age, double ves) {
        if (!head) return;

        if (head->name == beforeName) {
            Forward(name, age, ves);
            return;
        }

        Element* current = head;
        while (current->next) {
            if (current->next->name == beforeName) {
                Element* newElement = new Element{name, age, ves, current->next};
                current->next = newElement;
                return;
            }
            current = current->next;
        }
        std::cout << "Эелемент " << beforeName << " почему-то не нашелся \n";
    }
    void Delete(const std::string& name) {
        if (!head) return;

        if (head->name == name) {
            Element* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Element* current = head;
        while (current->next) {
            if (current->next->name == name) {
                Element* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        std::cout << "Элемент" << name << " почему-то не нашелся \n";
    }
    void Show() const {
        Element* current = head;
        while (current) {
            std::cout << "Имячко: " << current->name << ", Старость: " << current->age << ", Сила притяжения к земле без джоулей и притяжения: " << current->ves << "\n";
            current = current->next;
        }
    }

    ~List() {
        while (head) {
            Element* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main()
{
    List myList;

    myList.Back("Первый элемент", 1, 1.1);
    myList.Back("Второй элемент", 2, 2.2);
    myList.Forward("Нету элемента", 0, 0.0);
    myList.After_the_element("Первый элемент", "ахах элемент?", 1, 1.5);
    myList.Before_the_element("Второй элемент", "ыхых элемент", 1, 1.8);

    std::cout << "Ваши элементы таблицы Мендилеева:\n";
    myList.Show();

    myList.Delete("ахах элемент?");
    std::cout << "\n После ликвидации ахах элемента!:\n";
    myList.Show();

    return 0;
}
