#include <bits/stdc++.h>
#include <memory>

#if 0
6 4
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
<tag3>
</tag3>
tag1.tag2~name
tag1~name
tag1~value
tag3~name


6 3
<tag1 value = "value">
<tag2 name = "name">
<tag3 another="another" final="final">
</tag3>
</tag2>
</tag1>
tag1~value
tag1.tag2.tag3~name
tag1.tag2.tag3~final

10 10
<a value = "GoodVal">
<b value = "BadVal" size = "10">
</b>
<c height = "auto">
<d size = "3">
<e strength = "2">
</e>
</d>
</c>
</a>
a~value
b~value
a.b~size
a.b~value
a.b.c~height
a.c~height
a.d.e~strength
a.c.d.e~strength
d~sze
a.c.d~size
==============

GoodVal
Not Found!
10
BadVal
Not Found!
auto
Not Found!
2
Not Found!
3
#endif

using namespace std;
using namespace std::literals;

static const string kNotFound("Not Found!"sv);
constexpr string_view s_tag_start("<tag"sv);
constexpr string_view s_tag_end("</tag"sv);

struct Attr {
    string name{};
    string value{};
};

struct Tag {
    string name;
public:
    Tag(string_view n) : name(n) {
    }
    const string& get_name() const { return name; }
    vector<Attr> attrs{};
    vector<shared_ptr<Tag>> children{};
    const string& get_attr(const string_view& a_name) const {
        for (auto& a : attrs) {
            if (a.name == a_name)
                return a.value;
        }
        return kNotFound;
    }
};

vector<Attr> parse_attrs(string_view attrs) {
    vector<Attr> vattrs;
    // Expect: attribute1-name = "value1" attribute2-name = "value2" ...
    string::size_type pos = 0;
    bool in_key = true;
    Attr a;
    while (!attrs.empty()) {
        if (in_key) {
            pos = attrs.find_first_not_of(" ");
            if (pos != string_view::npos)
                attrs.remove_prefix(pos); // ltrim
            a.name = attrs.substr(0, std::min(attrs.find_first_of(" ="), attrs.size()));
            a.value.clear();
            attrs.remove_prefix(a.name.length());
            in_key = false;
            continue;  // go on to parse a value (if any)
        }
        pos = attrs.find_first_not_of(" =\"");
        if (pos == string_view::npos) {
            break; // empty value?
        }
        if (pos != string_view::npos)
            attrs.remove_prefix(pos); // ltrim delimiters
        pos = attrs.find_first_of("\"");
        if (pos == string_view::npos) {
            break; // no delimeter?
        }
        a.value = attrs.substr(0, pos);
        attrs.remove_prefix(a.value.length() + 1);
        in_key = true;
        vattrs.push_back(a);
    }

    return vattrs;
}

shared_ptr<Tag> parse_tags(const vector<string>& lines) {
    shared_ptr<Tag> root = make_shared<Tag>("root");
    stack<shared_ptr<Tag>> s;
    s.push(root);
    for (const auto& l : lines) {
        string_view tag(l); // assume trim() is not needed.
        if (tag.size() >= 3 && tag[0] == '<') {
            if (tag[1] != '/') {
                // found a new tag...
                tag.remove_prefix(1); // remove '<'
                auto pos = tag.find_first_of(" >");
                if (tag.empty())
                    continue; // illegal tag name
                string_view name = tag.substr(0, std::min(pos, tag.size()));
                shared_ptr<Tag> t = make_shared<Tag>(name);
                s.top()->children.push_back(t);
                s.push(t);
                //  If there are no attributes there is no space after tag name.
                tag.remove_prefix(name.size());
                if (tag.empty() || tag[0] != ' ')
                    continue;
                tag.remove_suffix(1); // remove '>' rtrim => find_last_not_of()
                if (tag.empty())
                    continue;
                t->attrs = parse_attrs(tag);
            } else if (tag[1] == '/') {
                // pop tag
                if (s.size() > 1)
                    s.pop();
            }
        }
    }
    s.pop();
    return root;
}

shared_ptr<Tag> find_tag(const shared_ptr<Tag>& root, string_view name) {
        for (auto& c : root->children) {
            if (c->get_name() == name)
                return c;
        }
        return shared_ptr<Tag>(nullptr);
}

// ----------------------------------------------------------------------------
void run_queries(const shared_ptr<Tag>& root, const vector<string>& queries) {
    // handle tag1.tag2~name
    for (const auto& q : queries) {
        shared_ptr<Tag> t = root;
        string_view qv = q;
        while (!qv.empty()) {
            if (qv[0] == '~') {
                qv.remove_prefix(1); // skip '~'
                string_view attr_name = qv.substr(0, std::min(qv.find_first_of(" "), qv.size()));
//printf("|--> attr: |%.*s|, tag: %s, t->attrs.size: %lu\n", (int)attr_name.length(), attr_name.data(), t->get_name().c_str(), t->attrs.size());
                cout << t->get_attr(attr_name) << endl;
                break;
            } else if (qv[0] == '.') {
                qv.remove_prefix(1); // skip '.'
            }

            string_view name = qv.substr(0, std::min(qv.find_first_of(".~"), qv.size()));
            qv.remove_prefix(name.length());
            // find tag
            t = find_tag(t, name);
            if (!t)
            {
                cout << kNotFound << endl;
                break;
            }
        }
    }
}

// ----------------------------------------------------------------------------
int main () {

    int n,q;
    cin >> n;
    cin >> q;
    cin.ignore(); // read '\n'

    // read the lines
    vector<string> lines(n);
    for (int i=0; i<n; i++) {
        getline (cin, lines[i]);
    }

    // read the queries
    vector<string> queries(q);
    for (int i=0; i<q; i++) {
        getline (cin, queries[i]);
    }

    shared_ptr<Tag> root = parse_tags(lines);

    run_queries(root, queries);

    return 0;
}
