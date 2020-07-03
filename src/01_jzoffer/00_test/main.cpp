#include "test.h"

BEGIN_INTERVIEW_NS
    extern void externFunction();
END_INTERVIEW_NS

USE_INTERVIEW_NS

#define COUNT 10000000
#define max_bit 5000000
#define max_sort 1000000

#include <cerrno>
#include <vector>
#include <string>

void testIO() {
    int intVal = 10;
    float fVal = 3.1415;
    double dVal = 1323300240.432423232;
    printf("input %d, %f %f\n", intVal, fVal, dVal);
    FILE *f = fopen("./file.bin", "w+");
    fwrite(&intVal, sizeof(int), 1, f);
    fwrite(&fVal, sizeof(float), 1, f);
    fwrite(&dVal, sizeof(double), 1, f);
    fclose(f);
    FILE *rf = fopen("./file1.bin", "r+");
    if (!rf) {
        printf("fopen error: %s\n", strerror(errno));
    }
    int iv = 0;
    float fv = 0.0;
    double dv = 0.0;
    fread(&iv, sizeof(int), 1, rf);
    fread(&fv, sizeof(float), 1, rf);
    fread(&dv, sizeof(double), 1, rf);
    fclose(rf);
    printf("output %d, %f %f\n", iv, fv, dv);
}


void generateBigFile() {
    srand(time(NULL));
    FILE *f = fopen("bigfile.txt", "w");
    for (int i = 0; i < 1000; i++) {
        int n = rand() % 100000000;
        fprintf(f, "%d ", n);
    }
    fclose(f);
    printf("100 values \n");
    FILE *r = fopen("bigfile.txt", "r");
    for (int i = 0; i < 100; i++) {
        int val;
        fscanf(r, "%d ", &val);
        printf("%d ", val);
    }
    printf("\n100 values end \n");
}


void quicksortcore(int *data, int begin, int end) {
    if (!data || begin >= end) return;
    int key = data[begin];
    int pos = begin;
    for (int i = pos + 1; i <= end; i++) {
        if (data[i] < key) {
            std::swap(data[i], data[++pos]);
        }
    }
    std::swap(data[begin], data[pos]);
    if (pos > begin) quicksortcore(data, begin, pos - 1);
    if (pos < end) quicksortcore(data, pos + 1, end);
}

void quiksort(int *data, int length) {
    quicksortcore(data, 0, length - 1);
}

void generateUniqueFile(int n, const char *path) {
    int *array = new int[n];
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int k = rand() % n;
        std::swap(array[j], array[k]);
    }
    FILE *f = fopen(path, "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", array[i]);
    }
    fclose(f);
}


void sortonefile(FILE *f, int maxMem) {
    if (!f) return;
    fseek(f, 0, SEEK_END);
    int len = ftell(f);
    if (len <= maxMem) {
        int *buf = new int[maxMem];
        int num = fread(buf, sizeof(int), 1, f);
        quiksort(buf, num);
        fseek(f, 0, SEEK_SET);
        fwrite(buf, sizeof(int), num, f);
        delete buf;
    }
}

void mergeFile(FILE *src1, FILE *src2, FILE *dst) {
    if (!src1 || !src2 || !dst) return;

    fseek(src1, 0, SEEK_SET);
    rewind(src2);
    fseek(dst, 0, SEEK_END);

    while (!feof(src2) && !feof(src1)) {
        int f1 = fgetc(src1);
        int f2 = fgetc(src2);
        int val = f1 < f2 ? f1 : f2;
        if (f1 < f2) {
            fseek(src2, -1, SEEK_CUR);
        } else {
            fseek(src1, -1, SEEK_CUR);
        }
        fputc(val, dst);
    }
    fclose(src1);
    fclose(src2);

}


void bigFileSort(const char *filePath, int maxMem) {
    FILE *f = fopen(filePath, "wb+");
    if (!f) {
        printf("open error %s\n", strerror(errno));
    }
    fseek(f, 0, SEEK_END);
    int len = ftell(f);
    fseek(f, 0, SEEK_SET);

    int filenum = len % maxMem == 0 ? len / maxMem : (len / maxMem + 1);

    FILE *tmp = fopen("tmp", "wb+");
    char name[32] = {};
    int *buf = new int[maxMem];
    std::vector<std::string> pathArray;
    for (int i = 0; i < filenum; i++) {
        sprintf(name, "subfile%d", i);
        int len = fread(buf, sizeof(int), 1, f);
        FILE *tf = fopen(name, "wb+");
        fwrite(buf, sizeof(int), 1, tf);
        fclose(tf);
    }
}


void sortBit(const char *path) {
    bitset<max_bit> bit_map;
    bit_map.reset();

    FILE *f = fopen(path, "r");
    if (!f) return;
    int num;

    while (fscanf(f, "%d ", &num) != EOF) {
        if (num < max_bit)
            bit_map.set(num, 1);
    }
    FILE *of = fopen("out.txt", "w");

    for (int i = 0; i < max_bit; i++) {
        if (bit_map[i] == 1) {
            fprintf(of, "%d ", i);
        }
    }

    if (fseek(f, 0, SEEK_SET)) return;
    bit_map.reset();
    while (fscanf(f, "%d ", &num) != EOF) {
        if (num >= max_bit && num < max_bit * 2)
            bit_map.set(num - max_bit, 1);
    }
    for (int i = 0; i < max_bit; i++) {
        if (bit_map[i] == 1)
            fprintf(of, "%d ", i + max_bit);
    }

    fclose(of);
}

string tempFileName(int i) {
    char name[32];
    sprintf(name, "tmp%d", i);
    return string(name);
}

int read_data(FILE *f, int *buf, int count) {
    int i = 0;
    while (i < count && fscanf(f, "%d ", &buf[i]) != EOF) {
        i++;
    }
    return i;
}

vector<string> splitAndSort(const char *path, int mCount) {


}

void mergeSortedFiles(vector<string> paths) {

}

void sortBigFile(const char *path, const char *outPath, int mCount) {
    FILE *f = fopen(path, "r");
    int *array = new int[mCount];
    int file_count = 0;
    int readSize = 0;
    char tmpName[32];
    do {
        readSize = 0;
        while (readSize < mCount && fscanf(f, "%d ", &array[readSize]) != EOF)
            readSize++;
        quiksort(array, readSize);
        sprintf(tmpName, "tmp%d.txt", file_count++);
        FILE *tmpFile = fopen(tmpName, "w");
        for (int i = 0; i < readSize; i++) {
            fprintf(tmpFile, "%d ", array[i]);
        }
        fclose(tmpFile);

    } while (readSize > 0);

    if (file_count <= 0) return;
    vector<FILE *> tmpFiles;
    tmpFiles.clear();
    for (int i = 0; i < file_count; i++) {
        sprintf(tmpName, "tmp%d.txt", i);
        FILE *tmpFile = fopen(tmpName, "r");
        tmpFiles.push_back(tmpFile);
    }


    FILE *outf = fopen(outPath, "w");

    //1.使用一个int数组记录取到的值
    //2.使用一个bool数组记录是否访问完
    int *data = new int[file_count];
    memset(data, 0, sizeof(int) * file_count);
    bool *end = new bool[file_count];
    memset(end, 0, sizeof(bool) * file_count);
    for (int i = 0; i < file_count; i++) {
        if (fscanf(tmpFiles[i], "%d", &data[i]) == EOF)
            end[i] = true;
    }


    //3.循环选择最小的写入out文件，记录最新的idx, 从idx文件读一下值，并更新是否读完的flag
    //结束条件为flag都为end
    while (true) {
        int index = 0;
        while (index < file_count && end[index]) {
            index++;
        }
        if (index >= file_count) break;
        int min = data[0];
        for (int i = 0; i < file_count; i++) {
            if (!end[i] && data[i] < min) {
                min = data[i];
                index = i;
            }
        }

        if (fscanf(tmpFiles[index], "%d ", &data[index]) == EOF)
            end[index] = true;

        fprintf(outf, "%d ", min);
    }
    delete[] data;
    delete[] end;
    fclose(outf);
    for (int i = 0; i < file_count; i++) {
        fclose(tmpFiles[i]);
    }

//    int *data = new int[file_count];
//    bool *hasNext = new bool[file_count];
//    memset(data, 0, sizeof(int) * file_count);
//    memset(hasNext, 1, sizeof(bool) * file_count);
//    for (int i = 0; i < file_count; ++i) {
//        if (fscanf(tmpFiles[i], "%d ", &data[i]) == EOF) {
//            hasNext[i] = false;
//        }
//    }
//    FILE *out = fopen(outPath, "w");
//    while (true) {
//        int min = data[0];
//        int j = 0;
//        while (j < file_count && !hasNext[j])
//            j++;
//        if (j >= file_count)
//            break;
//        for (int i = j + 1; i < file_count; ++i) {
//            if (hasNext[i] && min > data[i]) {
//                min = data[i];
//                j = i;
//            }
//        }
//        if (fscanf(tmpFiles[j], "%d", &data[j]) == EOF)
//            hasNext[j] = false;
//
//        fprintf(out, "%d ", min);
//    }
//    fclose(out);
//    for (int i = 0; i < file_count; i++) {
//        fclose(tmpFiles[i]);
//    }
}


int main() {
//    Foo &foo = getFoo();
//    printf("in main foo(%p) is %d\n", &foo, foo.getBar());
//    foo.setBar(5);
//    printf("in main foo(%p) is %d\n", &foo, foo.getBar());
//    printFoo();
//
//    externFunction();

//    generateBigFile();
//    testIO();
//    const char *path = "data.txt";
//    generateUniqueFile(COUNT, path);
//
//    FILE *f = fopen("data.txt", "r");
//    if (f) {
//        int n[100];
//        for (int i = 0; i < 100; i++) {
//            int v;
//            fscanf(f, "%d ", &v);
//            n[i] = v;
//        }
//        quiksort(n, 100);
//        for (int i = 0; i < 100; i++) {
//            printf("%d ", n[i]);
//        }
//    }

//    generateUniqueFile(COUNT, "big_data.txt");

    sortBigFile("big_data.txt", "out_data.txt", max_sort);
//    sortBit("bit_data.txt");

    return 0;
}