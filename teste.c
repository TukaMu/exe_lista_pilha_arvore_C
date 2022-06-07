struct no *restorna(struct no *noh)
{
    if (noh != NULL)
    {
        struct no *nohesq, *nohdir;
        nohesq = retorna(noh->fesq);
        nohdir = retorna(noh->fdir);

        if (nohdir != NULL && nohesq != NULL)
        {
            if (nohesq->val < noh->val)
            {
                if (nohdir->val < noh->val)
                {
                    if (nohdir->val < nohesq->val)
                    {
                        return nohesq;
                    }
                    else
                    {
                        return nohdir;
                    }
                }
                else
                {
                    return nohesq;
                }
            }
            else if (nohdir->val < noh->val)
            {
                return nohdir;
            }
            else
            {

                return noh;
            }
        }
    }
    return NULL;
}