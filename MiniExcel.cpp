#include <iostream>
using namespace std;
template <typename T>
class MiniExcel
{

public:
    MiniExcel()
    {
        intialize5_5();
    }
    class cell
    {
    public:
        T value;
        cell *next;
        cell *prev;
        cell *up;
        cell *down;
        int row;
        int col;
        cell(T val, int row, int col)
        {
            this->row = row;
            this->col = col;
            value = val;
            next = NULL;
            prev = NULL;
            up = NULL;
            down = NULL;
        }
    };
    class iterator
    {
    public:
        cell *ptr;
        iterator(cell *p)
        {
            ptr = p;
        }
        iterator operator++()
        {
            ptr = ptr->next;
            return *ptr;
        }
        iterator operator--()
        {
            ptr = ptr->prev;
            return *ptr;
        }
        iterator operator++(int)
        {

            ptr = ptr->down;
            return *ptr;
        }
        iterator operator--(int)
        {

            ptr = ptr->up;
            return *ptr;
        }
    };
    cell *active;
    cell *head;
    // intialize 5 by 5 cells by default and data is ""
    void intialize5_5()
    {

        cell *new_node = new cell('1', 0, 0);
        active = new_node;
        head = new_node;
        cell *temp = head;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cell *new_node2 = new cell('1', j + 1, i);
                temp->down = new_node2;
                new_node2->up = temp;
                temp = temp->down;
            }

            cell *new_node1 = new cell('1', 0, i + 1);
            temp = new_node1;
            new_node->next = new_node1;
            new_node1->prev = new_node;
            new_node = new_node->next;
        }
        for (int j = 0; j < 4; j++)
        {
            cell *new_node2 = new cell('1', j + 1, 4);
            temp->down = new_node2;
            temp = temp->down;
        }
        cell *h1 = head;
        cell *h2 = head->next;
        cell *t1 = h1;
        cell *t2 = h2;
        while (h2 != NULL)
        {
            t1 = h1;
            t2 = h2;
            for (int i = 0; i < 5; i++)
            {
                t1->next = t2;
                t2->prev = t1;
                t1 = t1->down;
                t2 = t2->down;
            }
            h1 = h2;
            h2 = h2->next;
        }
    }

    // print whole excel sheet
    void printSheet()
    {
        cell *temp = head;
        cell *tempRow = head;

        while(tempRow!=NULL)
        {
            temp = tempRow;
            while(temp!=NULL)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            tempRow = tempRow->down;
        }
    }
    void insertRowAbove()
    {

        cell *temp = rowStarter(active->row);

        if (temp != head)
        {
            cell *previous = NULL;

            while (temp != NULL)
            {

 
                cell *new_node = new cell('3', temp->row - 1, temp->up->col);
                new_node->down = temp;

                new_node->up = temp->up;
                temp->up->down=new_node;
                temp->up=new_node;
                temp->row++;
                if (previous != NULL)
                {
                    previous->next = new_node;
                    new_node->prev = previous;
                }
                previous = new_node;

                temp = temp->next;
            }
        }
        else
        {

            cell *original = temp;
            cell *previous = NULL;
            while (temp != NULL)
            {
                cell *new_node = new cell('2', 0, temp->col);
                new_node->down = temp;
                temp->up = new_node;
                temp->row++;
                if (previous != NULL)
                {
                    previous->next = new_node;
                    new_node->prev = previous;
                }
                previous = new_node;
                temp = temp->next;
            }
            head = original->up;
        }
    }
    cell *rowStarter(int i)
    {
        cell *temp = head;

        while (i > 0)
        {
            temp = temp->down;
            i--;
        }
        return temp;
    }
};
main()
{
    MiniExcel<char> m;
    m.insertRowAbove();
    
    m.insertRowAbove();
    m.insertRowAbove();


    m.printSheet();
}