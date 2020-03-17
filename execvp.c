int main(int argc, char const *argv[])
{
    execvp("shellPrograms/listdir", argv[1]);
    printf("BINARY: printing return value in binary\n");
    return 0;
}
