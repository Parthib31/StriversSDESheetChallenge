Node*temp=head;

vector<int>a;

while(temp)

{

a.push_back(temp->data);

temp=temp->next;

}

int sum=0;

for(int i=0;i<n;i++)

{

reverse(a.begin()+sum,min(a.begin()+sum+b[i],a.end()));

sum+=b[i];

}

temp=head;

int i=0;

while(temp)

{

temp->data=a[i++];

temp=temp->next;

}

return head;