#include "search_words.cpp"

int main(){
    vector<string> words = {
        "ababababaa", "ababababab", "ababababac", "ababababad", "ababababae",
        "ababababaf", "ababababag", "ababababah", "ababababai", "ababababaj",
        "ababababak", "ababababal", "ababababam", "ababababan", "ababababao",
        "ababababap", "ababababaq", "ababababar", "ababababas", "ababababat",
        "ababababau", "ababababav", "ababababaw", "ababababax", "ababababay",
        "ababababaz", "ababababba", "ababababbb", "ababababbc", "ababababbd",
        "ababababbe", "ababababbf", "ababababbg", "ababababbh", "ababababbi",
        "ababababbj", "ababababbk", "ababababbl", "ababababbm", "ababababbn",
        "ababababbo", "ababababbp", "ababababbq", "ababababbr", "ababababbs",
        "ababababbt", "ababababbu", "ababababbv", "ababababbw", "ababababbx",
        "ababababby", "ababababbz", "baba", "abababc", "abacababc"
    };

    vector<vector<char>> board = {
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','a','b','a','b','a','b'},
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','c','b','a','b','a','b'},
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','a','b','a','b','a','b'},
        {'b','a','b','a','b','a','b','a','b','a'},
        {'a','b','a','b','a','b','a','b','a','b'},
        {'b','a','c','a','b','a','b','a','b','a'},
        {'a','b','a','c','a','b','c','b','a','b'}
    };


    SearchWords ob1;

    auto res_words = ob1.findWords(board, words);

    ob1.show_result(res_words);

    return 0;
}