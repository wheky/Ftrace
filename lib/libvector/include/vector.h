/*
** vector.h for  in /home/pastek/42sh-2016-dinque_n/libvector
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  ven. avril 13 17:04:46 2012 jonathan tran
** Last update Mon Apr 30 14:50:32 2012 Chris
*/
#ifndef VECTOR_H_
#define VECTOR_H_

#define	vecCreate()		vectorCreate()
#define	vecDelete(v)		vectorDelete(v)
#define	vecGetDataPointer(n)	vectorGetDataPointer(n)
#define	vecRemoveNode(v, n)	vectorRemoveNode(v, n)
#define	vecPushFront(v, o)	vectorPushFrontEx(v, (void *) &(o), sizeof(o))
#define	vecPushBack(v, o)	vectorPushBackEx(v, (void *) &(o), sizeof(o))
#define	vecPushFrontEx(v, p, s)	vectorPushFrontEx(v, p, s)
#define	vecPushBackEx(v, p, s)	vectorPushBackEx(v, p, s)
#define	vecPopFront(v)		vectorPopFront(v)
#define	vecPopBack(v)		vectorPopBack(v)
#define	vecBrowse(v, c)		vectorBrowse(v, c)
#define	vecBrowseEx(v, c, o)	vectorBrowseEx(v, c, &(o))
#define	vecFind(v, c, o)	vectorFind(v, c, &(o))

typedef	int		(*vector_callback_t)();

typedef struct		vector_node_s
{
  struct vector_node_s	*previous;
  struct vector_node_s	*next;
} vector_node_t;

typedef struct		vector_s
{
  vector_node_t		*front;
  vector_node_t		*back;
  vector_callback_t	onAdd;
  vector_callback_t	onRemove;
  unsigned		size;
} vector_t;

vector_t		*vectorCreate();
void			vectorDelete(vector_t *);
void			*vectorGetDataPointer(vector_node_t *);
void			vectorRemoveNode(vector_t *, vector_node_t *);
void			vectorPushFrontEx(vector_t *, void *, unsigned);
void			vectorPushBackEx(vector_t *, void *, unsigned);
void			vectorPopFront(vector_t *);
void			vectorPopBack(vector_t *);
void			vectorBrowse(vector_t *, vector_callback_t);
void			vectorBrowseEx(vector_t *, vector_callback_t, void *);
vector_node_t		*vectorFind(vector_t *, vector_callback_t, void *);
void			vectorRemoveMulti(vector_t *, vector_callback_t, void *);

#endif
