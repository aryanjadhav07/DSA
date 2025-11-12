    #include<iostream>
    using namespace std;

    int main(){
        int n;
        cout << "Enter the number of files : ";
        cin >> n;

        int cap;
        cout << "Enter the capacity : ";
        cin >> cap;

        int size[20], imp[20];
        cout << "Enter the size and importance of each file : " << endl ;
        for(int i = 1; i <= n; i++){
            cout << "Enter the size of file " << i << " : ";
            cin >> size[i];
            cout << "Enter the importance of file "<< i << " : ";
            cin >> imp[i];
        }

        int dp[20][20];

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= cap; j++){
                dp[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= cap; j++){
                if(size[i] <= j){
                    dp[i][j] = max(imp[i] + dp[i-1][j - size[i]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        int w = cap;
        int selected[20], count = 0;
        for(int i = n; i > 0 && w > 0; i--){
            if(dp[i][w] != dp[i-1][w]){
                selected[count++] = i;
                w -= size[i];
            }
        }

        cout << "Selected files : ";
        int totalSize = 0, totalImp = 0;
        for(int i = count - 1; i >= 0; i--){
            int idx = selected[i];
            cout << "File " << idx << " (Size: " << size[idx] << ", Importance : " << imp[idx] << ")" << endl;    
            totalSize += size[idx];
            totalImp += imp[idx];
            }

            cout << "Total size used : " << totalSize << endl;
            cout << "Totla importance : " << totalImp << endl;

    }   

