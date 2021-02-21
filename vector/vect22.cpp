#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review {
    std::string title;
    int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);


int main(){
    using std::cout;
    using std::endl;
    using std::vector;

    vector<Review> books;
    Review temp;

    while (FillReview(temp)){
        books.push_back(temp);
    }

    int num = books.size();
    if(num > 0){
        cout << "Thank you. You entered the following:\n"
        << "Rating\tBook\n";
        for (int i = 0; i < num; i++){
            ShowReview(books[i]);
        }

        cout << "Reprising(by iterator):\n" << "Rating\tBook\n";

        vector<Review>::iterator pr;

        for_each(books.begin(), books.end(), ShowReview);

        vector<Review> oldlist(books);

        if (num > 3)
        {
            //remove 2 items;
            books.erase(books.begin(), books.begin() + 2);
        }
        cout << "After erase 2 items:\n";

        // for (pr = books.begin(); pr != books.end(); pr++){
        //     ShowReview(*pr);
        // }
        for_each(books.begin(), books.end(), ShowReview);

        books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 3);

        cout << "After insert 2 items (oldlist[begin+1], oldlist[begin+3])" << endl;

        // for (pr = books.begin(); pr != books.end(); pr++){
        //     ShowReview(*pr);
        // }
        for_each(books.begin(), books.end(), ShowReview);

        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        // for (pr = books.begin(); pr != books.end(); pr++){
        //     ShowReview(*pr);
        // }
        for_each(books.begin(), books.end(), ShowReview)
    }
    else{
        cout << "Noting entered, nothing gained.\n";
    }

    cout << books.size() << endl;
    return 0;
}

bool FillReview(Review & rr){
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin , rr.title);
    if(rr.title == "quit"){
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if(!std::cin){
        return false;
    }
    while (std::cin.get() != '\n')
    {
        continue;
    }
    return true;
    
}
void ShowReview(const Review &rr){
    std::cout << rr.rating << " " << rr.title  << std::endl;
}