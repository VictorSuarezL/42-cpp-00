# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <Contact.hpp>
#include <iomanip>
#include <string>
#include <Phonebook_utils.hpp>

class Phonebook 
{
    private:
        Contact _contacts[8];
        int _index;
        void _print_ui(Contact contact[8]);
        void _calculate_padding(std::string &str);
    
    public:
        Phonebook(void);
        ~Phonebook(void);

        void add(void);
        void search();
        void print(Contact contact);

        Contact get_contact(int index);
};



#endif

