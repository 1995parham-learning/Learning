/*
 * In The Name Of God
 * ========================================
 * [] File Name : process_dir.h
 *
 * [] Creation Date : 15-02-2015
 *
 * [] Last Modified : Sun 15 Feb 2015 01:40:19 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
struct filestr;
typedef void (*level_fn)(struct filestr path);

struct filestr {
	char *name, *fullname;
	level_fn directory_action, file_action;
	int depth, error;
	void *data;
};

/*
 * I get the contents of the given directory, run file_action on each
 * file, and for each directory run dir_action and recurse into directory.
 * Note that this makes the traversal depth first (DFS).
 *
 * Your function will take in a filestr. Note that there is an error element,
 * which you can set to one to indicate an error.
 *
 * Inputs are designated initializers, and may include:
 * .name The current file or directory name
 * .fullname The path of the current file or directory
 * .directory_action A function that takes in a filestr
 *                   I will call it with an appropriately-set filestr
 *                   for every directory (just before the files in the directory
 *                   are processed).
 * .file_action Like the directory_action, but the function I will call for every
 *              non-directory file.
 * .data A void pointer to be passed in to your functions.
*/

#define process_dir(...) \
	process_dir_r((struct filestr){__VA_ARGS__})

int process_dir_r(struct filestr level);
