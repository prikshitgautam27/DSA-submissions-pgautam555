class Solution {
public:
int square_sum(int n){
    int sum=0;
    while(n>0){
    int lastd=n%10;// return the last digit
   
    sum+=lastd*lastd;
 n=n/10; //return removing the tens place
    }
    return sum;
}

    bool isHappy(int n) {
        set<int>mset;
        while(true){
            if(n==1){
                return true;

            }
            if(mset.find(n)!=mset.end()){
                return false;
            }
            mset.insert(n);
            n=square_sum(n);
        }
    }
};
