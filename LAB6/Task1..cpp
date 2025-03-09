#include <iostream>
using namespace std;

class message {
private:
    string text;
public:
    string toString() const {
        return text;
    }
    void settext(const string& str) { this->text = str; }
};

class SMS : public message {
    string recipientContactNo;
public:
    void setcontactNum(const string& number) { this->recipientContactNo = number; }
    string getContactNum() const { return recipientContactNo; }
    string toString() const {
        string concatenated_string = recipientContactNo + " " + message::toString();
        return concatenated_string;
    }
};

class Email : public message {
private:
    string sender;
    string receiver;
    string subject;
public:
    string getsender() const { return sender; }
    string getreceiver() const { return receiver; }
    string getsubject() const { return subject; }
    void setsender(const string& sender) { this->sender = sender; }
    void setreceiver(const string& receiver) { this->receiver = receiver; }
    void setsubject(const string& subject) { this->subject = subject; }
    string toString() const {
        string concatenated_string = sender + " " + receiver + " " + subject + " " + message::toString();
        return concatenated_string;
    }
};

bool ContainsKeyword(const message& messageObject, const string& keyword) {
    string text = messageObject.toString();
    int textLength = text.length();
    int keywordLength = keyword.length();
    bool found = false;

    for (int i = 0; i <= textLength - keywordLength; i++) {
        found = true; 
        for (int j = 0; j < keywordLength; j++) {
            if (text[i + j] != keyword[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            break; 
        }
    }
    return found; 
}

void encode(message& messageObject) { 
    string text = messageObject.toString();
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] >= 'a' && text[i] < 'z') || (text[i] >= 'A' && text[i] < 'Z')) {
            text[i]++;
        }
        else if (text[i] == 'z' || text[i] == 'Z') {
            text[i] -= 25;
        }
    }
    messageObject.settext(text);
}

int main() {
    SMS objsms;
    string smsText = "Hello, this is an SMS!";
    string contactNo = "1234567890";
    objsms.settext(smsText);
    objsms.setcontactNum(contactNo);
    cout << "SMS: " << objsms.toString() << endl;

    Email objemail;
    string emailText = "This is an email.";
    string sender = "sender@example.com";
    string receiver = "receiver@example.com";
    string subject = "Test Email";
    objemail.settext(emailText);
    objemail.setsender(sender);
    objemail.setreceiver(receiver);
    objemail.setsubject(subject);
    cout << "Email: " << objemail.toString() << endl;

    string keyword = "SMS";
    if (ContainsKeyword(objsms, keyword)) {
        cout << "Keyword '" << keyword << "' found in SMS." << endl;
    }
    else {
        cout << "Keyword '" << keyword << "' not found in SMS." << endl;
    }

    encode(objsms);
    cout << "Encoded SMS: " << objsms.toString() << endl;

    return 0;
}