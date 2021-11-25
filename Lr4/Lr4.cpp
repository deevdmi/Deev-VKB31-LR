#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
typedef std::string                         T_str;
typedef size_t                              T_person;
typedef std::list<T_person>                 T_bad_persons;
typedef std::map<T_person, T_bad_persons>   T_bad_persons_for_person;
const T_person  PERSON_MIN = 1;
enum  T_table
{
    NO_TABLE = 0,
    TABLE_1,
    TABLE_2
};

typedef std::map<T_person, T_table>         T_table_of_person;

bool  successfully_depth_first_search
    (
        T_person                            person,
        const T_bad_persons_for_person&     bad_persons_for_person,
        T_table_of_person&                  table_of_person
    )
{    
    if(table_of_person[person] == NO_TABLE)
    {
        table_of_person[person] = TABLE_1;
    }    
    
    T_bad_persons_for_person::const_iterator  
        person_and_bad_persons_it = bad_persons_for_person.find(person);
 
    if( person_and_bad_persons_it == bad_persons_for_person.end() )
    {
        return  true;
    }
 
    T_bad_persons  bad_persons = person_and_bad_persons_it->second;
    
    for(
        T_bad_persons::const_iterator 
        bad_person_it = bad_persons.begin();
        bad_person_it != bad_persons.end();
        ++bad_person_it
       )
    {
        if(
            table_of_person[*bad_person_it] == table_of_person[person]  
          )
        {
            return  false;
        }
        else if(
                table_of_person[*bad_person_it] == NO_TABLE
               )
        {
            table_of_person[*bad_person_it] =   table_of_person[person] == TABLE_1
                                                    ? TABLE_2
                                                    : TABLE_1;
 
            if(
                !successfully_depth_first_search
                    (
                        *bad_person_it,
                        bad_persons_for_person,
                        table_of_person
                    )  
              )
            {
                return  false;
            }
        }//else if    
    }//for
    return  true;
}

bool  successfully_to_seat
    (
        const T_bad_persons_for_person&     bad_persons_for_person,
        T_table_of_person&                  table_of_person        
    )
{    
    for(T_table_of_person::iterator  person_and_table_it = table_of_person.begin();
        person_and_table_it != table_of_person.end(); ++person_and_table_it)
    {
        if(person_and_table_it->second != NO_TABLE) continue;
        
        if(
            !successfully_depth_first_search
                (
                    person_and_table_it->first,
                    bad_persons_for_person,
                    table_of_person
                ) 
          )
        {
            return  false;
        }       
    }
    return  true;
}

void  input_persons_data
        (
            const T_str&                ifile_name,
            T_table_of_person&          table_of_person,
            T_bad_persons_for_person&   bad_persons_for_person
        )
{
    std::ifstream   ifile( ifile_name.c_str() );
 
    int  persons_total          = 0;
    ifile >> persons_total;
 
    for(T_person  person = PERSON_MIN; person <= persons_total; ++person)
    {
        table_of_person[person] = NO_TABLE;
    }
    
    int  persons_pairs_total    = 0;
    ifile >> persons_pairs_total;
 
    for(int  i = 0; i < persons_pairs_total; ++i)
    {
        int  L = 0;
        ifile >> L;        
 
        int  R = 0;
        ifile >> R;        
        
        bad_persons_for_person[L].push_back(R);
        bad_persons_for_person[R].push_back(L);
    } 
}

void  print_persons_placement_at_tables
    (
        const T_str&                ofile_name,
        bool                        persons_are_successfully_seated,        
        const T_table_of_person&    table_of_person
    )
{
    std::ofstream   ofile( ofile_name.c_str() );
    ofile   <<  (
                    persons_are_successfully_seated 
                        ? "YES" 
                        : "NO"
                )
 
            << std::endl;               
 
    if(persons_are_successfully_seated)
    {
        for(T_table_of_person::const_iterator  person_and_table_it = table_of_person.begin();
            person_and_table_it != table_of_person.end(); ++person_and_table_it)
        {
            if(person_and_table_it->second == TABLE_1)
            {
                ofile   << person_and_table_it->first
                        << " ";
            }
        }
        ofile << std::endl;
    }
}

int main()
{
    const T_str     ifile_name = "input.txt";           
    const T_str     ofile_name = "output.txt";
 
    
    T_bad_persons_for_person    bad_persons_for_person;
    T_table_of_person           table_of_person;
 
    input_persons_data
        (
            ifile_name,
            table_of_person,
            bad_persons_for_person
        );   
 
    bool        bool_res =  successfully_to_seat
                                (
                                    bad_persons_for_person,
                                    table_of_person                                    
                                );
 
    print_persons_placement_at_tables
        (
            ofile_name,
            bool_res,            
            table_of_person
        );                    
}