import pandas as pd

single_sym_dict = {"+": "plus", "-": "minus", "*": "times", "/": "slash", "=": "eql", "#": "neq",
                   "<": "lss", ">": "gtr", "(": "lparen", ")": "rparen", ",": "comma",
                   ";": "semicolon", ".": "period"}
double_sym_dict = {"<=": "leq", ">=": "geq", ":=": "becomes"}


def rec_sym(sentence: str) -> list:
    now: int = 0
    sym_result: list = []

    tmp_num: str = ""
    tmp_word: str = ""
    while now < len(sentence):
        while (now < len(sentence) and (sentence[now] == " "
                                        or sentence[now] == '\t'
                                        or sentence[now] == '\n'
                                        or sentence[now] == '\r')):
            now += 1

        # 判断数字
        while now < len(sentence) and ('0' <= sentence[now] <= '9'):
            tmp_num += sentence[now]
            now += 1
        if len(tmp_num) != 0:
            sym_result.append(["number", tmp_num])
            tmp_num: str = ""
            continue

        # 识别单词
        if (now < len(sentence) and
                (('a' <= sentence[now] <= 'z') or ('A' <= sentence[now] <= 'Z'))):
            tmp_word += sentence[now]
            now += 1
            while (now < len(sentence) and
                   (('a' <= sentence[now] <= 'z') or ('A' <= sentence[now] <= 'Z') or ('0' <= sentence[now] <= '9'))):
                tmp_word += sentence[now]
                now += 1
            lower_word: str = tmp_word.lower()
            if lower_word in ["begin", "call", "const", "do", "end", "if", "odd",
                              "procedure", "read", "then", "var", "while", "write"]:
                sym_result.append([lower_word + "sym", lower_word])
            else:
                sym_result.append(["ident", lower_word])
            tmp_word = ""
            continue

        # 识别单个符号
        if (now < len(sentence) and sentence[now] in single_sym_dict.keys()
                and (sentence[now] != '>' and sentence[now] != '<')):
            sym_result.append([single_sym_dict[sentence[now]], sentence[now]])
            now += 1

        # 识别双符号
        if (now + 1 < len(sentence) and ((sentence[now] == '<' or sentence[now] == '>' or sentence[now] == ':')
                                         and sentence[now + 1] == "=")):
            sym_result.append([double_sym_dict[sentence[now] + sentence[now + 1]], sentence[now] + sentence[now + 1]])
            now += 2
            continue

        if now < len(sentence) and (now == '<' or sentence[now] == '<' or sentence[now] == '>'):
            sym_result.append([single_sym_dict[sentence[now]], sentence[now]])
            now += 1
            continue

    return sym_result


def save_sym(test_path: str, save_path: str) -> None:
    test_file = open(test_path)
    test_sentences: list = test_file.read().split("\n")

    test_result: list = []
    for test_sentence in test_sentences:
        test_tmp: list = rec_sym(test_sentence)
        test_result.extend(test_tmp)

    result_save = pd.DataFrame(data=test_result, columns=["种别码", "内容"])
    result_save.to_csv(save_path, index=False)


if __name__ == "__main__":
    # save_sym("test_1.txt", "./result_1.csv")
    # save_sym("test_2.txt", "./result_2.csv")
    # save_sym("test_3.txt", "./result_3.csv")
    # save_sym("test_4.txt", "./result_4.csv")
    save_sym("test_5.txt", "./result_5.csv")
