#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

// 查询结果
class QueryResult {
    friend ostream& operator<<(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr <set<line_no>> p,
        shared_ptr<vector<string>> f) :
        sought(s), lines(p), file(f) {}
    auto begin() { return lines->begin(); }
    auto end() { return lines->end(); }
    auto get_file() { return file; }
private:
    string sought;     // 待查询的单词
    shared_ptr<set<line_no>> lines;     // 查询结果的行号
    shared_ptr<vector<string>> file;    // 文件文本
};
ostream& operator<<(ostream& os, const QueryResult& q) {
    os << q.sought << " occurs " << q.lines->size() << " "
        << "times" << endl;
    for (auto num : *q.lines)
        os << "\t(line " << num + 1 << ") "
        << *(q.file->begin() + num) << endl;
    return os;
}

// 文件文本转换
class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file;            // 文件文本
    map<string, shared_ptr<set<line_no>>> wm;   // 单词与行号的映射
};
TextQuery::TextQuery(ifstream& is) : file(new vector<string>) {
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);  // 用字符串流处理一行中的单词
        string word;
        while (line >> word) {
            auto& lines = wm[word];
            if (!lines)     // 如果当前单词的行集合为空，则分配一个新的set集合
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}
QueryResult TextQuery::query(const string& sought) const {      // 查找单词
    static shared_ptr<set<line_no>> nodata(new set<line_no>);   // 空的set指针
    auto loc = wm.find(sought);
    if (loc == wm.end())        // 没有找到则置空
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

// 规范查找类的抽象基类
class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

// 查找的接口类
class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
    friend ostream& operator<<(ostream& os, const Query& query);
public:
    Query(const string&);
    QueryResult eval(const TextQuery& t) const { return q->eval(t); }   //进行查找
    string rep() const { return q->rep(); }     // 返回待查找的信息
private:
    Query(shared_ptr<Query_base> query) : q(query) {}
    shared_ptr<Query_base> q;
};
ostream& operator<<(ostream& os, const Query& query) {
    return os << query.rep();
}

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const string& s) : query_word(s) {}
    QueryResult eval(const TextQuery& t) const {
        return t.query(query_word);
    }
    string rep() const { return query_word; }
    string query_word;
};

inline Query::Query(const string& s) : q(new WordQuery(s)) {}

class NotQuery : public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query& q) : query(q) {}
    string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};
inline Query operator~(const Query& operand) {
    return shared_ptr<Query_base>(new NotQuery(operand));
}
QueryResult NotQuery::eval(const TextQuery& text) const {
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

// 二元查找运算符的抽象基类
class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query& l, const Query& r, const string& s) :
        lhs(l), rhs(r), opSym(s) {}
    string rep() const {
        return "(" + lhs.rep() + " "
            + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    string opSym;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right) :
        BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery&) const;
};
inline Query operator&(const Query& lhs, const Query& rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
QueryResult AndQuery::eval(const TextQuery& text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(),
        right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right) :
        BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery&) const;
};
inline Query operator|(const Query& lhs, const Query& rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
QueryResult OrQuery::eval(const TextQuery& text) const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

int main() {
    ifstream file("data.txt");
    if (!file)
        return -1;
    TextQuery text(file);
    Query q = Query("hair") & Query("Alice");
    cout << q.eval(text);

    return 0;
}