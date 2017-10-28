#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef enum Type{file,directory}type;

typedef struct Filesystem{
	type f_or_d;
	char name[100];
	int childcount;
	struct Filesystem *children;
}filesystem;

void create_file(filesystem *curr,char *name,int childcount){
	if(curr->f_or_d==file){
		printf("A file can't have a sub-file\n");
		return;
	}
	if(childcount==0){
		curr->children = (filesystem *)malloc(sizeof(filesystem));
		++(curr->childcount);
		strcpy((curr->children)->name,name);
		curr->children->f_or_d = file;
		curr->children->childcount = 0;

	}
	else{
		curr->children = (filesystem *)realloc(curr->children,((curr->childcount)+1)*sizeof(filesystem));
		if(curr->children==NULL){
			printf("Reallocation failed!\n");
		}
		else{
			strcpy((curr->children[curr->childcount]).name,name);
			curr->children[curr->childcount].f_or_d = file;
			curr->children[curr->childcount].childcount = 0;				
			++(curr->childcount);		
		}
	}
}

int index_directory(filesystem *curr,char *name){
	//printf("In index directory\n");
	int i;
	for(i=0;i<curr->childcount;i++){
		//printf("%s\n",curr->children[i].name);
		if(strcmp(name,curr->children[i].name)==0){
			return i;
		}
	}
	//printf("End of index_directory");
	return -1;
}

filesystem * parse_path(filesystem *curr,char *name){

	//char *my_str_literal = "comeon/sid/you/can/do/this";
	int count=0;
	//printf("\nIn parse path now:\n");
	char *token, *str, *tofree;
	filesystem *temp = curr;
	tofree = str = strdup(name);  // We own str's memory now.
	while ((token = strsep(&str, "/"))) {
		if(strcmp(token,"\0")!=0){
		//printf("\nIn %d count\n",count);	
		//printf("%s\n",token);
		int idx = index_directory(temp,token);
		//printf("%d is the index",idx);
		if(idx==-1){
			printf("\nInvalid path\n");
			return NULL;
		}
		temp = &(temp->children[idx]);
	}
	count++;
	}
	free(tofree);
	return temp;

}

void list_contents(filesystem *curr){
	int i;
	printf("Files\n");
	for(i=0;i<curr->childcount;i++){
		if(curr->children[i].f_or_d==file){
		printf("%s\n",curr->children[i].name);
		}
	}
	printf("Directories\n");
	for(i=0;i<curr->childcount;i++){
		if(curr->children[i].f_or_d==directory){
		printf("%s\n",curr->children[i].name);
		}
	}	
}

void recursive_print(filesystem *curr){
	if(curr!=NULL){
	int loop = curr->childcount;
	int i;
	for(i=0;i<loop;i++){
		list_contents(&curr->children[i]);
		recursive_print(&curr->children[i]);
	}
	}
}

void check_func(filesystem *curr,char *name){
		//char *my_str_literal = "comeon/sid/you/can/do/this";
	char *token, *str, *tofree;
	filesystem *temp = curr;
	tofree = str = strdup(name);  // We own str's memory now.
	while ((token = strsep(&str, "/"))) {
		printf("%s\n",token);
		//temp = &temp->children[idx];
	}
	free(tofree);


}

void create_directory(filesystem *curr,char *name,int childcount){
	if(childcount==0){
		curr->children = (filesystem *)malloc(sizeof(filesystem));
		++(curr->childcount);
		strcpy((curr->children)->name,name);
		curr->children->f_or_d = directory;
		curr->children->childcount = 0;

	}
	else{
		curr->children = (filesystem *)realloc(curr->children,((curr->childcount)+1)*sizeof(filesystem));
		if(curr->children==NULL){
			printf("Reallocation failed!\n");
		}
		else{
			strcpy((curr->children[curr->childcount]).name,name);
			curr->children[curr->childcount].f_or_d = directory;
			curr->children[curr->childcount].childcount = 0;				
			++(curr->childcount);		
		}
	}
}




int main(){
	filesystem root;
	root.childcount=0;
	strcpy(root.name,"/");
	root.f_or_d = directory;
	filesystem *curr = &root;
	char name[50];
	char path[100];
	while(1){
		printf("Enter 0 to create a file\nEnter 1 to create a directory\nEnter 2 for listing files and directories\nEnter 3 for switching into a directory\nEnter 4 for fucking yourself!\n");
		int choice;
		scanf("%d",&choice);
		if(choice==0){
			printf("Enter filename\n");
			scanf("%s",name);
			create_file(curr,name,curr->childcount);
		}
		else if(choice==1){
			printf("Enter the directory\n");
			scanf("%s",name);
			create_directory(curr,name,curr->childcount);
		}
		else if(choice==2){
			list_contents(curr);
		}
		else if(choice==3){
			printf("Enter the path:\n");
			scanf("%s",path);
			char *asli_path = path;
			if(path[0]=='/'){
				//check_func(&root,asli_path);
				if(parse_path(&root,asli_path)!=NULL){
					curr = parse_path(&root,asli_path);
				}
			}
			else{
				//check_func(curr,asli_path);
				if(parse_path(curr,asli_path)!=NULL){
					curr = parse_path(curr,asli_path);
					printf("%s> ",curr->name);
				}				
			}

		}
		else{
			recursive_print(&root);
		}

	}	

	return 0;
}