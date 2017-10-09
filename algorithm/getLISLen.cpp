int getLISLen(string &str){
    if(str.size()==0||str.size()==1)
        return str.size();
    int len=str.size();
    int *hsh=new int[len];
    for(int i=0;i<len;++i)
        hsh[i]=1;
    for(int i=1;i<len;++i){
        for(int j=0;j<i;++j){
            if(str[j]<str[i]&&hsh[j]+1>hsh[i])
                hsh[i]=hsh[j]+1;
        }
    }
    int maxlen=0;
    for(int i=0;i<len;++i){
        if(hsh[i]>maxlen)
            maxlen=hsh[i];
    }

    delete []hsh;
    return maxlen;

}
