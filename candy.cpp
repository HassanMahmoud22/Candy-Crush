#include <bits/stdc++.h>
using namespace std;
const int MIN = 3;
const int N = 7;
char arr[N][N];
char Fruits[5] = { 'A', 'B', 'C', 'D','E'};
vector<pair<int,int>> idxs;
int score = 0;
void clear_grid()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr[i][j] = '.';
        }
    }
}
void random_grid_first()
{
    char fruit;
    srand(time(0));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(arr[i][j] == '.')
                arr[i][j] = Fruits[rand() % 5];
        }
    }
}
void random_grid_second()
{
    char fruit;
    srand(time(0));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(arr[i][j] == '.')
                arr[i][j] = Fruits[rand() % 5];
        }
    }
}
void print_grid() {
	cout << "--";
    for (int i = 0; i < N; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < N; cout << "---", i++);
        cout << "--\n";
    }
}
void delete_duplicate(){
    int k;
    char temp;
    for(int i = 0; i < idxs.size(); i++){
        if(idxs[i].first == idxs[i+1].first && idxs[i].second == idxs[i+1].second && i + 1 < idxs.size()){
            k = 0;
            temp = arr[idxs[i].first][idxs[i].second];
            while(arr[idxs[i].first + k][idxs[i].second] == temp){
                arr[idxs[i].first + k][idxs[i].second] = '.';
                k++;
            }
            k = 1;
            while(arr[idxs[i].first][idxs[i].second + k] == temp){
                arr[idxs[i].first][idxs[i].second + k] = '.';
                k++;
            }
        }
        else{
            temp = arr[idxs[i].first][idxs[i].second];
            k = 0;
            if(arr[idxs[i].first][idxs[i].second] == arr[idxs[i].first + 1][idxs[i].second] && arr[idxs[i].first + 1][idxs[i].second] == arr[idxs[i].first + 2][idxs[i].second]){
                while(arr[idxs[i].first + k][idxs[i].second] == temp){
                    arr[idxs[i].first + k][idxs[i].second] = '.';
                    k++;
                }
            }
            else{
                while(arr[idxs[i].first][idxs[i].second + k] == temp){
                    arr[idxs[i].first][idxs[i].second + k] = '.';
                    k++;
                }
            }
        }
        score += k;
    }
}
void swap(int i, int j, int i2, int j2){
    char temp = arr[i][j];
    arr[i][j] = arr[i2][j2];
    arr[i2][j2] = temp;
}
bool isduplicated (int i, int j, int i2, int j2){
    swap(i,j,i2,j2);
    if(i + 2 < N && arr[i][j] == arr[i+1][j]  && arr[i+1][j] == arr[i+2][j]){
            return true;
    }
    else if(i2 + 2 < N && arr[i2][j2] == arr[i2+1][j2] && arr[i2+1][j2] == arr[i2+2][j2]){
            return true;
    }
    else if(i - 2 > -1 && arr[i][j] == arr[i-1][j] && arr[i-1][j]  == arr[i-2][j]){
            return true;
    }
    else if(i2 - 2 > -1 && arr[i2][j2] == arr[i2-1][j2] && arr[i2-1][j2] == arr[i2-2][j2]){
            return true;
    }
    else if(i + 1 < N && i - 1 > -1 && arr[i][j] == arr[i+1][j] && arr[i+1][j]== arr[i-1][j]){
            return true;
    }
    else if(i2 + 1 < N && i2 - 1 > -1 && arr[i2][j2] == arr[i2-1][j2] && arr[i2-1][j2] == arr[i2+1][j2]){
            return true;
    }
    else if(j + 2 < N && arr[i][j] == arr[i][j+1] && arr[i][j+1]== arr[i][j+2]){
            return true;
    }
    else if(j2 + 2< N && arr[i2][j2] == arr[i2][j2+1] && arr[i2][j2+1] == arr[i2][j2+2]){
            return true;
    }
    else if(j - 2 > -1 && arr[i][j] == arr[i][j-1] && arr[i][j-1] == arr[i][j-2]){
            return true;
    }
    else if(j2 - 2 > -1 && arr[i2][j2] == arr[i2][j2 - 1] && arr[i2][j2 - 1]  == arr[i2][j2 - 2]){
            return true;
    }
    else if(j2 - 1 > -1 && j2 + 1 < N && arr[i2][j2] == arr[i2][j2+1] && arr[i2][j2+1] == arr[i2][j2-1]){
            return true;
    }
    else if(j - 1 > -1 && j + 1 < N && arr[i][j] == arr[i][j-1] && arr[i][j-1] == arr[i][j+1]){
            return true;
    }
    else{
        swap(i,j,i2,j2);
        return false;
    }
}
void move_fruits(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[j][i] == '.'){
                for(int k = j; k > 0; k--){
                    arr[k][i] = arr[k - 1][i];
                    arr[k - 1][i] = '.';
                }
            }
        }
    }
}
void check_Rows()
{
    for(int i = 0 ; i < N ; i++)
    {
        int start = 0;
        int dup = 1;
        for(int j = 0 ; j < N-1 ; j++)
        {
            if(arr[i][j] == arr[i][j+1] && j+1 != N-1)
            {
                dup+=1;
            }
            else if(arr[i][j] == arr[i][j+1] && j+1 == N-1)
            {
                dup+=1;
                if(dup >= MIN)
                {
                    pair<int,int> point;
                    point.first = i;
                    point.second = start;
                    idxs.push_back(point);
                }
            }
            else
            {
                if(dup >= MIN)
                {
                    pair<int,int> point;
                    point.first = i;
                    point.second = start;
                    idxs.push_back(point);
                }
                start = j+1;
                dup=1;
            }
        }
    }
}
void check_Cols()
{
    for(int i = 0 ; i < N ; i++)
    {
        int start = 0;
        int dup = 1;
        for(int j = 0 ; j < N-1 ; j++)
        {
            if(arr[j][i] == arr[j+1][i] && j+1 != N-1)
            {
                dup+=1;
            }
            else if(arr[j][i] == arr[j+1][i] && j+1 == N-1)
            {
                dup+=1;
                if(dup >= MIN)
                {
                    pair<int,int> point;
                    point.first = start;
                    point.second = i;
                    idxs.push_back(point);
                }
            }
            else
            {
                if(dup >= MIN)
                {
                    pair<int,int> point;
                    point.first = start;
                    point.second = i;
                    idxs.push_back(point);
                }
                start = j+1;
                dup=1;
            }
        }
    }
}
// A function to implement bubble sort
void bubbleSort()
{
    int i, j;
    for (i = 0; i < idxs.size()-1; i++){
        for (j = 0; j < idxs.size()-i-1; j++){
            if (idxs[j].first > idxs[j+1].first){
                int temp = idxs[j].first;
                idxs[j].first = idxs[j+1].first;
                idxs[j+1].first = temp;
                int temp1 = idxs[j].second;
                idxs[j].second = idxs[j+1].second;
                idxs[j+1].second = temp1;
            }
        }
    }
    for (i = 0; i < idxs.size()-1; i++){
        for (j = 0; j < idxs.size()-i-1; j++){
            if (idxs[j].first == idxs[j+1].first && idxs[j].second > idxs[j+1].second ){
                int temp = idxs[j].first;
                idxs[j].first = idxs[j+1].first;
                idxs[j+1].first = temp;
                int temp1 = idxs[j].second;
                idxs[j].second = idxs[j+1].second;
                idxs[j+1].second = temp1;
            }
        }
    }
}
bool check_duplicates()
{
    while(!idxs.empty()){
        idxs.pop_back();
    }
    check_Rows();
    check_Cols();
    if(idxs.size() == 0)
        return false;
    bubbleSort();
    return true;
}
void replace_duplicate(){
    srand(time(0));
    char temp = Fruits[rand() % 5];
    for(int i = 0; i < idxs.size(); i++){
        while(temp == arr[idxs[i].first][idxs[i].second]){
            temp = Fruits[rand() % 5];
        }
        arr[idxs[i].first][idxs[i].second] = temp;
    }
}
bool check_valid_input(int i,int j,int k,int m)
{
    int test1 = abs(k-i);
    int test2 = abs(m-j);
    if (i==k && j == m )
        return false;
    else if (test1 != 1  &&  test2 != 1 )
        return false;
    else
        return true;
}
void take_input(int &i,int &j,int &k,int &m){
    do{
        cout<<"Enter first point"<<endl;
        cin>>i>>j;
        cout<<"Enter second point"<<endl;
        cin>>k>>m;
    }
    while(!check_valid_input(i,j,k,m) || !isduplicated(i,j,k,m));
}
void play_game(){
    score = 0;
    int i,j,i2,j2;
    clear_grid();
    random_grid_first();
    while(check_duplicates()){
        replace_duplicate();
    }
    while(score < 10){
        print_grid();
        take_input(i,j,i2,j2);
        while(check_duplicates()){
            delete_duplicate();
            move_fruits();
            random_grid_second();
            print_grid();
        }
        cout<<" Your Score:"<<score<<endl;
    }
}
int main()
{
    while (true) {
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
