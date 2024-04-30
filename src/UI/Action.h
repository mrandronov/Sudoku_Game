#ifndef __LIB_ACTION_H__
#define __LIB_ACTION_H__

class Action
{
        public:
                virtual int action() = 0;
};

class NewGameAction : public Action
{
        public:
                virtual int action() override;
};

class QuitGameAction : public Action
{
        public:
                virtual int action() override;
};

class NumberSelectAction : public Action
{
        public:
                int             selectedNumber = 1;

                NumberSelectAction( int number );

                virtual int     action()        override;
};

class UndoMoveAction : public Action
{
        public:
                int             move = 0;

                UndoMoveAction();

                virtual int     action()        override;
};

#endif /* __LIB_ACTION_H__ */