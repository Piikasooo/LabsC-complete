#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

class Member{
    private:
        int id;
        string name;
        int membership;
    public:
        Member(int id, string name, int membership = 0)
        {
            if(id <= 0)
                throw invalid_argument("ID can't be <= 0");
            if(name.empty())
                throw invalid_argument("Name can't be empty");
            if(membership < 0)
                throw invalid_argument("Membership can't be < 0");
            this->id = id;
            this->name = name;
            this->membership = membership;
        }
        int Id()
        {
            return id;
        }
        string Name()
        {
            return name;
        }
        int Membership()
        {
            return membership;
        }
        void SetName(string name)
        {
            if(name.empty())
                throw invalid_argument("Name can't be empty");
            this->name = name;
        }
        void ExtendMembership(int membership)
        {
            if(membership <= 0)
                throw invalid_argument("Can't extend membership by value that <= 0");
            this->membership += membership;
        }
        void CancelMembership()
        {
            this->membership = 0;
        }
        void PrintMember()
        {
            cout << "Member "<< id << ": " << name <<", subscription valid for " << membership << " months" << endl;
        }
};

Member& findMemberById(vector<Member> &members, int id)
{
    vector<Member>::iterator member;
    for(member = members.begin(); member < members.end(); ++member)
        if(member->Id() == id)
        {
            return *member;
        }

    throw invalid_argument("This member doesn't exists.");
}

bool MemberWithThisIdExists(vector<Member> members, int id)
{
    vector<Member>::iterator member;
    for(member = members.begin(); member < members.end(); ++member)
        if(member->Id() == id)
        {
            return true;
        }

    return false;
}

void removeMemberById(vector<Member> &members, int id)
{
    vector<Member>::iterator member;
    for(member = members.begin(); member < members.end(); ++member)
        if(member->Id() == id)
        {
            members.erase(member);
            return;
        }

    throw invalid_argument("This member doesn't exists.");
}

void lookMembers(vector<Member> members)
{
    vector<Member>::iterator member;
    for(member = members.begin(); member < members.end(); ++member)
        member->PrintMember();
    cout << endl;
}

int main()
{
    string command;
    string name;
    int id, membership;
    vector<Member> members;
    istringstream iss;

    do
    {
        cout << "Enter a command:" << endl;
        getline(cin, command);
        iss.str(command);

        try
        {
            iss >> command;
            if(command == "create")
            {
                iss >> id;
                if(iss.fail())
                    throw invalid_argument("U don't entered id.");
                if(MemberWithThisIdExists(members, id))
                    throw invalid_argument("Member with this Id already exists.");
                getline(iss, name);
                members.push_back(Member(id, name));
                lookMembers(members);
            }
            else
                if(command == "delete")
                {
                    iss >> id;
                    if(iss.fail())
                        throw invalid_argument("U don't entered id.");
                    removeMemberById(members, id);
                    lookMembers(members);
                }
            else
                if(command == "extend")
                {
                    iss >> id;
                    if(iss.fail())
                        throw invalid_argument("U don't entered id.");
                    iss >> membership;
                    if(iss.fail())
                        throw invalid_argument("U don't entered membership.");
                    findMemberById(members, id).ExtendMembership(membership);
                    lookMembers(members);
                }
            else
                if(command == "cancel")
                {
                    iss >> id;
                    if(iss.fail())
                        throw invalid_argument("U don't entered id.");
                    findMemberById(members, id).CancelMembership();
                    lookMembers(members);
                }
        }
        catch (const exception& e)
        {
            cout << "Cannot perform this operation, because: " << e.what() << endl << endl;
        }

        iss.clear();
    } while (command != "quit");

    return 0;
}
