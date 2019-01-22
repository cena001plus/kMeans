​

struct Data{
float para1;
float para2;
};

void cluster(int ,int, int *pClass, struct Data *data, struct Data *newCore);
void GetNewCenter(int ,int, int *pClass, struct Data *data, struct Data *newCore);
void kMeans(int ,int, int *pClass, struct Data *data, struct Data *newCore);

​